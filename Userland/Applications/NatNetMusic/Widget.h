#pragma once

#include <LibCore/Timer.h>
#include <LibGUI/HorizontalSlider.h>
#include <LibGUI/Label.h>
#include <LibGUI/Widget.h>

class Widget final : public GUI::Widget {
    C_OBJECT(Widget)
public:
    virtual ~Widget() override = default;

    virtual void time_elapsed(int);
    virtual void count_elapsed(int);
    virtual void volume_changed(int);
    virtual void mute_changed(bool);
    virtual void toggle_play();
private:
    Widget();

    RefPtr<Core::Timer> m_play_timer;

    RefPtr<Gfx::Bitmap> m_play_icon;
    RefPtr<Gfx::Bitmap> m_pause_icon;
    RefPtr<Gfx::Bitmap> m_stop_icon;
    RefPtr<Gfx::Bitmap> m_back_icon;
    RefPtr<Gfx::Bitmap> m_next_icon;
    RefPtr<Gfx::Bitmap> m_volume_icon;
    RefPtr<Gfx::Bitmap> m_muted_icon;

    RefPtr<GUI::Action> m_play_action;
    RefPtr<GUI::Action> m_stop_action;
    RefPtr<GUI::Action> m_back_action;
    RefPtr<GUI::Action> m_next_action;
    RefPtr<GUI::Action> m_mute_action;

    RefPtr<GUI::HorizontalSlider> m_playback_progress_slider;
    RefPtr<GUI::Label> m_volume_label;
    RefPtr<GUI::HorizontalSlider> m_volume_slider;
    RefPtr<GUI::Label> m_timestamp_label;

    RefPtr<GUI::Label> m_4am;
    RefPtr<GUI::Label> m_falling;
    RefPtr<GUI::Label> m_happy;

    int m_count { 0 };
    bool m_muted { false };
    bool m_playing { false };
};
