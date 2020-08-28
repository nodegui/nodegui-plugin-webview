import {
  QObject,
  Component,
  NativeElement,
  checkIfNativeElement,
} from "@nodegui/nodegui";
import addon from "./utils/addon";

export class QWebChannel extends Component {
  native: NativeElement;
  constructor(arg?: NativeElement | QObject) {
    super();
    if (checkIfNativeElement(arg)) {
      this.native = arg as NativeElement;
    } else if (arg instanceof QObject) {
      this.native = new addon.QWebChannel(arg.native);
    } else if (!arg) {
      this.native = new addon.QWebChannel(new QObject().native);
    } else {
      throw new Error(
        "QWebChannel cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  registerObject(name: string, obj: QObject): void {
    this.native.registerObject(name, obj.native);
  }

  deregisterObject(obj: QObject): void {
    this.native.deregisterObject(obj.native);
  }
}
