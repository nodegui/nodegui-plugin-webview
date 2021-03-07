import path from 'path';
import { WidgetAttribute, WidgetEventTypes, QColor } from "@nodegui/nodegui";
import { QWebEngineView, QWebChannel } from "./index";

const webview = new QWebEngineView();

const index = 'file://' + path.resolve(__dirname, '..', 'public/index.html');

webview.setAttribute(WidgetAttribute.WA_TranslucentBackground, true);
webview.setAttribute(WidgetAttribute.WA_OpaquePaintEvent, true);

webview.load(index);

webview.addEventListener("urlChanged", (url) => {
  console.log("changed to", url);
});

webview.addEventListener("selectionChanged", () => {
  console.log("selection", webview.property("selectedText").toString());
});

webview.addEventListener("loadFinished", () => {
  const js = `alert('nodeui');`;
  const page = webview.page();
  page.runJavaScript(js);  
});

webview.addEventListener(WidgetEventTypes.Paint, () => {
  webview.setStyleSheet('background:transparent');
  webview.setInlineStyle("align-self:'stretch';");
});

const channel = new QWebChannel();
webview.page().setWebChannel(channel);
webview.page().setBackgroundColor(new QColor(255,0,0,0));

webview.show();
(global as any).wv = webview;