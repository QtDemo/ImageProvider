import QtQuick 2.0
import CustomModel 1.0

Rectangle {
    visible: true
    width: 640
    height: 480
    color: "lightblue"

    Column {
        Image { source: "image://colors/red" }

        Image { source: "image://colors/yellow" }

        PaintedItem { }
    }
}
