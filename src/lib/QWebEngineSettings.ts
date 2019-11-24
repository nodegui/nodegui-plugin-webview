import {
  Component,
  NativeElement,
  checkIfNativeElement
} from "@nodegui/nodegui";

export class QWebEngineSettings extends Component {
  native: NativeElement;
  constructor(native: NativeElement) {
    super();
    if (checkIfNativeElement(native)) {
      this.native = native;
    } else {
      throw new Error(
        "QWebEngineSettings cannot be initialised this way. Use webengineview.settings()"
      );
    }
  }
  setUnknownUrlSchemePolicy(policy: UnknownUrlSchemePolicy): void {
    this.native.setUnknownUrlSchemePolicy(policy);
  }
}

export enum UnknownUrlSchemePolicy {
  DisallowUnknownUrlSchemes = 1,
  AllowUnknownUrlSchemesFromUserInteraction,
  AllowAllUnknownUrlSchemes
}
