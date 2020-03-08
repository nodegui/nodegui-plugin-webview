import { QWebEngineView } from "./index";
// import {
//   QMainWindow,
//   QWidget,
//   FlexLayout,
//   QPushButton
// } from "@nodegui/nodegui";

// const win = new QMainWindow();
// const center = new QWidget();
const webview = new QWebEngineView();
webview.setInlineStyle("align-self:'stretch';");
webview.load("http://google.com");
webview.addEventListener("urlChanged", url => {
  console.log("changed to", url);
});
webview.addEventListener("selectionChanged", () => {
  console.log("selection", webview.property("selectedText").toString());
});

webview.show();
(global as any).wv = webview;

// const button = new QPushButton();
// button.setText("Hello");

// center.setLayout(new FlexLayout());
// center.layout?.addWidget(webview);
// center.layout?.addWidget(button);
// win.setCentralWidget(center);
// win.show();
// (global as any).win = win;
