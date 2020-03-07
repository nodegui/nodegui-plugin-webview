import { QWebEngineView } from "./index";
import { QMainWindow } from "@nodegui/nodegui";

const win = new QMainWindow();
const webview = new QWebEngineView();
webview.setInlineStyle("align-self:'stretch';");
webview.load("http://google.com");
webview.addEventListener("urlChanged", url => {
  console.log("changed to", url);
});
webview.addEventListener("selectionChanged", () => {
  console.log("selection", webview.property("selectedText").toString());
});

// webview.show();
win.setCentralWidget(webview);
win.show();
(global as any).win = win;
