import { QWebEngineView } from "./index";

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
