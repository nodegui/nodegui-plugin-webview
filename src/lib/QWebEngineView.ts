import {
  NativeElement,
  NodeWidget,
  QUrl,
  QWidgetSignals
} from "@nodegui/nodegui";
import addon from "./utils/addon";
import { QWebEngineSettings } from "./QWebEngineSettings";
import { QWebEnginePage } from "./QWebEnginePage";

export interface QWebEngineViewSignals extends QWidgetSignals {
  loadFinished: (ok: boolean) => void;
  loadProgress: (progress: number) => void;
  loadStarted: () => void;
  selectionChanged: () => void;
  urlChanged: (url: string) => void;
  titleChanged: (title: string) => void;
}

export class QWebEngineView extends NodeWidget<QWebEngineViewSignals> {
  native: NativeElement;
  constructor(parent?: NodeWidget<any>) {
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
  load(url: string) {
    this.setProperty("url", url);
  }
  url(): QUrl {
    return QUrl.fromQVariant(this.property("url"));
  }
  settings(): QWebEngineSettings {
    return new QWebEngineSettings(this.native.settings());
  }

  page(): QWebEnginePage {
    return new QWebEnginePage(this.native.page());
  }
}
