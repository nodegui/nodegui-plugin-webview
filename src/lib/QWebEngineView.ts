import {
  NativeElement,
  BaseWidgetEvents,
  NodeWidget,
  QUrl
} from "@nodegui/nodegui";
import addon from "./utils/addon";
import { QWebEngineSettings } from "./QWebEngineSettings";

export const QWebEngineViewEvents = Object.freeze({
  ...BaseWidgetEvents,
  loadFinished: "loadFinished",
  loadProgress: "loadProgress",
  loadStarted: "loadStarted",
  selectionChanged: "selectionChanged",
  urlChanged: "urlChanged",
  titleChanged: "titleChanged"
});

export class QWebEngineView extends NodeWidget {
  native: NativeElement;
  constructor(parent?: NodeWidget) {
    let native;
    if (parent) {
      native = new addon.QWebEngineView(parent.native);
    } else {
      native = new addon.QWebEngineView();
    }
    super(native);
    this.native = native;
    this.nodeParent = parent;
  }
  load(url: QUrl) {
    this.setProperty("url", url);
  }
  url(): QUrl {
    return QUrl.fromQVariant(this.property("url"));
  }
  settings(): QWebEngineSettings {
    return new QWebEngineSettings(this.native.settings());
  }
}
