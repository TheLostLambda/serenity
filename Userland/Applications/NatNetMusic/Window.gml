@GUI::Widget {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {
        margins: [4]
    }

    @GUI::GroupBox {
        preferred_height: "fit"
        layout: @GUI::VerticalBoxLayout {
            margins: [8]
        }

        @GUI::HorizontalSplitter {
            layout: @GUI::HorizontalBoxLayout {
                spacing: 4
            }

            @GUI::Frame {
                name: "label_frame"
                preferred_width: 140
                layout: @GUI::VerticalBoxLayout {
                    margins: [3, 4]
                }

                @GUI::TextBox {
                    placeholder: "Search"
                }

                @GUI::Widget {
                    preferred_height: "shrink"
                    layout: @GUI::VerticalBoxLayout {
                        margins: [2, 2]
                    }

                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {}

                        @GUI::Button {
                            text: "All"
                        }

                        @GUI::Button {
                            text: "Artists"
                        }
                    }

                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {}

                        @GUI::Button {
                            text: "Songs"
                        }

                        @GUI::Button {
                            text: "Playlists"
                        }
                    }
                    
                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {}

                        @GUI::Button {
                            text: "Albums"
                        }

                        @GUI::Button {
                            text: "Genres"
                        }
                    }
                }
                
                @GUI::HorizontalSeparator

                @GUI::Button {
                    text: "SURPRISE ME!"
                }

                @GUI::HorizontalSeparator

                @GUI::ImageWidget {
                    bitmap: "/res/icons/32x32/app-screenshot.png"
                }
            }

            @GUI::Frame {
                frame_style: "SunkenContainer"
                layout: @GUI::VerticalBoxLayout {
                    margins: [4, 4]
                }

                @GUI::Label {
                    name: "word_wrap_label"
                    word_wrap: true
                    text_alignment: "TopLeft"
                    font_size: 24
                    text: "Lorem ipsum sistema serenitas, per construxit klingre sed quis awesomatia, ergo salve amici."
                }

                @GUI::Label {
                    word_wrap: true
                    text_alignment: "TopRight"
                    font_size: 12
                    text: "Lorem ipsum sistema serenitas, per construxit klingre sed quis awesomatia, ergo salve amici."
                }
            }
        }

        @GUI::ToolbarContainer{
            @GUI::Widget {
                preferred_height: "shrink"
                layout: @GUI::VerticalBoxLayout {
                    margins: [4, 0]
                }

                @GUI::HorizontalSlider {
                    name: "seek-slider"
                    min: 0
                    max: 100
                    fixed_height: 20
                    enabled: true
                    jump_to_cursor: true
                }
            }

            @GUI::Toolbar {
                name: "play-controls"
                fixed_height: 22
                layout: @GUI::HorizontalBoxLayout {}
            }
        }
    }
}
