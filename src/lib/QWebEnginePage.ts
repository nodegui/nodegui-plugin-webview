import {
  Component,
  NativeElement,
  checkIfNativeElement
} from "@nodegui/nodegui";

export class QWebEnginePage extends Component {
  native: NativeElement;
  constructor(native: NativeElement) {
    super();
    if (checkIfNativeElement(native)) {
      this.native = native;
    } else {
      throw new Error(
        "QWebEnginePage cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  runJavaScript(script: string): void {
    this.native.runJavaScript(script);
  }
}

