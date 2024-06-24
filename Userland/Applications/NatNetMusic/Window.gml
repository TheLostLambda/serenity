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
                    bitmap: "/res/graphics/natnet/enlist.png"
                }
            }

            @GUI::Frame {
                frame_style: "SunkenContainer"
                layout: @GUI::VerticalBoxLayout {
                    margins: [4, 4]
                }

                @GUI::Widget {
                    preferred_height: "shrink"
                    layout: @GUI::HorizontalBoxLayout {
                        margins: [0, 0, 4, 0]
                    }

                    @GUI::ImageWidget {
                        bitmap: "/res/graphics/natnet/sadbot.png"
                    }

                    @GUI::Label {
                        width: 4
                    }

                    @GUI::Widget {
                        layout: @GUI::VerticalBoxLayout {}

                        @GUI::Label {
                            font: "Liza"
                            font_size: 36
                            text: "SADBOT"
                        }

                        @GUI::Widget {
                            layout: @GUI::VerticalBoxLayout {}

                            @GUI::Label {
                                text_alignment: "CenterLeft"
                                font: "Liberation Sans"
                                font_size: 14
                                text: "Location: Sheffield, BF\nGenre: Synthpop\nFollowers: 142,857"
                            }
                        }

                        @GUI::Frame {
                            preferred_height: 70
                            frame_style: "SunkenPanel"
                            layout: @GUI::VerticalBoxLayout {
                                margins: [4, 4]
                            }

                            @GUI::Label {
                                text_alignment: "TopLeft"
                                font_size: 12
                                font: "Lucidity"
                                text: "Blending pre-war synth soundscapes with modern production, sadbot provides a soundtrack to your nostalgic ruminations"
                            }
                        }
                    }
                }

                @GUI::HorizontalSeparator

                @GUI::Widget {
                    layout: @GUI::VerticalBoxLayout {}
                    
                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {}

                        @GUI::Label {
                            font: "Liberation Sans"
                            font_size: 14
                            text: "Top Songs"
                        }

                        @GUI::Label {
                            font: "Liberation Sans"
                            font_size: 14
                            text: "Listens"
                        }
                    }

                    @GUI::HorizontalSeparator

                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {
                            margins: [0, 16]
                        }

                        @GUI::Label {
                            text_alignment: "CenterLeft"
                            font: "Liberation Sans"
                            font_size: 12
                            text: "4 AM (Fashionably Lonely)"
                        }

                        @GUI::Label {
                            name: "4am"
                            font: "Liberation Sans"
                            font_size: 12
                            text: "..."
                        }
                    }

                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {
                            margins: [0, 16]
                        }

                        @GUI::Label {
                            text_alignment: "CenterLeft"
                            font: "Liberation Sans"
                            font_size: 12
                            text: "The Loser"
                        }

                        @GUI::Label {
                            name: "falling"
                            font: "Liberation Sans"
                            font_size: 12
                            text: "..."
                        }
                    }

                    @GUI::Widget {
                        layout: @GUI::HorizontalBoxLayout {
                            margins: [0, 16]
                        }

                        @GUI::Label {
                            text_alignment: "CenterLeft"
                            font: "Liberation Sans"
                            font_size: 12
                            text: "Happy Just To Be Yours"
                        }

                        @GUI::Label {
                            name: "happy"
                            font: "Liberation Sans"
                            font_size: 12
                            text: "..."
                        }
                    }
                }
            }
        }

        @GUI::ToolbarContainer{
            @GUI::Widget {
                preferred_height: "shrink"
                layout: @GUI::HorizontalBoxLayout {
                    margins: [4, 4, 4, 0]
                }

                @GUI::HorizontalSlider {
                    name: "seek-slider"
                    min: 0
                    max: 100
                    fixed_height: 20
                    enabled: true
                    jump_to_cursor: true
                }

                @GUI::Button {
                    min_width: 50
                    preferred_width: "shrink"
                    text: "Fave"
                }

                @GUI::Button {
                    min_width: 50
                    preferred_width: "shrink"
                    text: "Loop"
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
