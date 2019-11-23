import { NativeElement, BaseWidgetEvents, NodeWidget } from "@nodegui/nodegui";
import addon from "./utils/addon";

export const QWebEngineViewEvents = Object.freeze({
  ...BaseWidgetEvents
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
  // showMessage(message: string, timeout: number) {
  //   this.native.showMessage(message, timeout);
  // }
}
