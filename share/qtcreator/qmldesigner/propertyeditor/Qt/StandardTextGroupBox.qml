import Qt 4.6
import Bauhaus 1.0

GroupBox {
    id: standardTextGroupBox

    caption: "Text";

    property bool showIsWrapping: false
    property bool showVerticalAlignment: false

    layout: VerticalLayout {
        QWidget {
            layout: HorizontalLayout {

                Label {
                    text: "Text"
                }

                LineEdit {
                    backendValue: backendValues.text
                    baseStateFlag: isBaseState;
                }
            }
        }
        QWidget {
            visible: showIsWrapping
            layout: HorizontalLayout {
                Label {
                    text: ""
                }
                CheckBox {
                    baseStateFlag: isBaseState;
                    text: "Is Wrapping";
                    checkable: true;
                    backendValue: backendValues.wrap;
                }
            }
        }

        QWidget {
            layout: HorizontalLayout {

                Label {
                    text: "Alignment"
                }
                AlignmentHorizontalButtons {}
                AlignmentVerticalButtons { visible: showVerticalAlignment }
            }
        }       
    }
}
