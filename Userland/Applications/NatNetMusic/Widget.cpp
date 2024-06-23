#include "Widget.h"
#include <AK/Format.h>
#include <AK/NumberFormat.h>
#include <Applications/NatNetMusic/NNWindowGML.h>
#include <LibGUI/HorizontalSlider.h>
#include <LibGUI/Toolbar.h>
#include <LibGUI/Action.h>
#include <cmath>

Widget::Widget()
{
    load_from_gml(window_gml).release_value_but_fixme_should_propagate_errors();

    m_play_timer = Core::Timer::create_repeating(250, [this] {
        ++m_count;
        if (m_count <= 400) {
            time_elapsed(m_count / 4);
            count_elapsed(m_count);
        } else {
            toggle_play();
        }
    });

    m_playback_progress_slider = *find_descendant_of_type_named<GUI::HorizontalSlider>("seek-slider");
    m_playback_progress_slider->on_change = [&](int value) {
        m_count = 4 * value;
        time_elapsed(m_count / 4);
        count_elapsed(m_count);
    };

    auto& play_controls = *find_descendant_of_type_named<GUI::Toolbar>("play-controls");

    m_play_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/play.png"sv).release_value_but_fixme_should_propagate_errors();
    m_pause_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/pause.png"sv).release_value_but_fixme_should_propagate_errors();
    m_stop_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/stop.png"sv).release_value_but_fixme_should_propagate_errors();
    m_back_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/go-back.png"sv).release_value_but_fixme_should_propagate_errors();
    m_next_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/go-forward.png"sv).release_value_but_fixme_should_propagate_errors();
    m_volume_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/audio-volume-medium.png"sv).release_value_but_fixme_should_propagate_errors();
    m_muted_icon = Gfx::Bitmap::load_from_file("/res/icons/16x16/audio-volume-muted.png"sv).release_value_but_fixme_should_propagate_errors();

    m_play_action = GUI::Action::create("Play", { Key_Space }, m_play_icon, [&](auto&) {
        toggle_play();
    });
    play_controls.add_action(*m_play_action);

    m_stop_action = GUI::Action::create("Stop", { Key_S }, m_stop_icon, [&](auto&) {
        if (m_playing) {
            toggle_play();
        }
        m_count = 0;
        time_elapsed(m_count);
        count_elapsed(m_count);
    });
    play_controls.add_action(*m_stop_action);

    play_controls.add_separator();

    m_timestamp_label = play_controls.add<GUI::Label>();
    m_timestamp_label->set_fixed_width(110);
    time_elapsed(m_count / 4);

    // Filler label
    play_controls.add<GUI::Label>();

    m_back_action = GUI::Action::create("Back", m_back_icon, [&](auto&) {
        outln("Back!");
    });
    play_controls.add_action(*m_back_action);

    m_next_action = GUI::Action::create("Next", m_next_icon, [&](auto&) {
        outln("Next!");
    });
    play_controls.add_action(*m_next_action);

    play_controls.add_separator();

    m_mute_action = GUI::Action::create("Mute", { Key_M }, m_volume_icon, [&](auto&) {
        m_muted = !m_muted;
        mute_changed(m_muted);
    });
    play_controls.add_action(*m_mute_action);

    m_volume_label = &play_controls.add<GUI::Label>();
    m_volume_label->set_fixed_width(30);

    m_volume_slider = &play_controls.add<GUI::HorizontalSlider>();
    m_volume_slider->set_fixed_width(95);
    m_volume_slider->set_min(0);
    m_volume_slider->set_max(150);
    m_volume_slider->set_value(100);
    volume_changed(m_volume_slider->value());

    m_volume_slider->on_change = [&](int value) {
        volume_changed(value);
    };

    m_4am = *find_descendant_of_type_named<GUI::Label>("4am");
    m_falling = *find_descendant_of_type_named<GUI::Label>("falling");
    m_happy = *find_descendant_of_type_named<GUI::Label>("happy");
    count_elapsed(m_count);
}

void Widget::time_elapsed(int seconds)
{
    m_playback_progress_slider->set_value(seconds);
    m_timestamp_label->set_text(String::formatted("Elapsed: {}", human_readable_digital_time(seconds)).release_value_but_fixme_should_propagate_errors());
}

void Widget::count_elapsed(int count)
{
    int m_4am_count = 15672 + (count * 54) + pow(1.05, count);
    int m_falling_count = 1712 + (count * 17);
    int m_happy_count = 7689 + (count * 33);
    m_4am->set_text(String::formatted("{:'d}", m_4am_count).release_value_but_fixme_should_propagate_errors());
    m_falling->set_text(String::formatted("{:'d}", m_falling_count).release_value_but_fixme_should_propagate_errors());
    m_happy->set_text(String::formatted("{:'d}", m_happy_count).release_value_but_fixme_should_propagate_errors());
}

void Widget::volume_changed(int volume)
{
    m_volume_label->set_text(String::formatted("{}%", volume).release_value_but_fixme_should_propagate_errors());
}

void Widget::mute_changed(bool muted)
{
    m_mute_action->set_text(muted ? "Unmute"sv : "Mute"sv);
    m_mute_action->set_icon(muted ? m_muted_icon : m_volume_icon);
    m_volume_slider->set_enabled(!muted);
}

void Widget::toggle_play()
{
    m_playing = !m_playing;
    if (m_playing) {
        m_play_timer->start();
    } else {
        m_play_timer->stop();
    }
    m_play_action->set_text(m_playing ? "Pause"sv : "Play"sv);
    m_play_action->set_icon(m_playing ? m_pause_icon : m_play_icon);
}
