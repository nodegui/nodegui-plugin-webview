import { QMainWindow, FlexLayout, QWidget } from "@nodegui/nodegui";
import { QWebEngineView } from "./index";

const win = new QMainWindow();
const rootView = new QWidget();
rootView.setObjectName("root");
rootView.setLayout(new FlexLayout());

const webview = new QWebEngineView();
webview.setInlineStyle("align-self:'stretch';");

if (rootView.layout) {
  rootView.layout.addWidget(webview);
}

win.setCentralWidget(rootView);
win.setStyleSheet(`
  #root {
    flex: 1;
    height: '100%';
    align-items: 'center';
    justify-content: 'space-around';
  }
`);
win.setWindowTitle("NodeGUI Demo");
win.resize(400, 700);
win.show();

(global as any).win = win; // To prevent win from being garbage collected.
