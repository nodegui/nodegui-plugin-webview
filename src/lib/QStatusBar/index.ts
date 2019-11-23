import { NativeElement, BaseWidgetEvents, NodeWidget } from "@nodegui/nodegui";
import addon from "../utils/addon";

export const QStatusBarEvents = Object.freeze({
  ...BaseWidgetEvents
});

export class QStatusBar extends NodeWidget {
  native: NativeElement;
  constructor(parent?: NodeWidget) {
    let native;
    if (parent) {
      native = new addon.QStatusBar(parent.native);
    } else {
      native = new addon.QStatusBar();
    }
    super(native);
    this.native = native;
    this.nodeParent = parent;
    // bind member functions
    this.showMessage.bind(this);
  }
  showMessage(message: string, timeout: number) {
    this.native.showMessage(message, timeout);
  }
}
