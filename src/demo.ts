import {
  QMainWindow,
  FlexLayout,
  QWidget,
  QLabel,
  QUrl
} from "@nodegui/nodegui";
import { QWebEngineView } from "./index";
import { QWebEngineViewEvents } from "./lib/QWebEngineView";

const win = new QMainWindow();
const rootView = new QWidget();
rootView.setObjectName("root");
rootView.setLayout(new FlexLayout());
const text = new QLabel();
text.setText("NodeGui web view");
rootView.layout?.addWidget(text);
const webview = new QWebEngineView();
webview.setInlineStyle("align-self:'stretch';");
webview.load(new QUrl("http://google.com"));
webview.addEventListener(QWebEngineViewEvents.urlChanged, url => {
  console.log("changed to", url);
});
webview.addEventListener(QWebEngineViewEvents.selectionChanged, () => {
  console.log("selection", webview.property("selectedText").toString());
});
rootView.layout?.addWidget(webview);

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
setTimeout(() => {
  console.log(webview.url().toString(), "Url from webview");
}, 10000);

(global as any).win = win; // To prevent win from being garbage collected.
