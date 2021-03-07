import path from 'path';
import { WidgetAttribute, WidgetEventTypes, QPainter, QColor, PenStyle, WindowType } from "@nodegui/nodegui";
import { QWebEngineView, QWebChannel } from "nodegui-plugin-webview";

const index = 'file://' + path.resolve(__dirname, '..', 'public/index.html');

const webview = new QWebEngineView();

webview.setAttribute(WidgetAttribute.WA_TranslucentBackground, true);
webview.setAttribute(WidgetAttribute.WA_OpaquePaintEvent, true);
webview.setAttribute(WidgetAttribute.WA_AlwaysStackOnTop, true);

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

const color = new QColor('transparent');

webview.addEventListener(WidgetEventTypes.Paint, () => {
  webview.page().setBackgroundColor(color);
});

const channel = new QWebChannel();
webview.page().setWebChannel(channel);
webview.page().setBackgroundColor(color);

webview.show();
(global as any).wv = webview;