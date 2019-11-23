import {
  QMainWindow,
  QPushButton,
  FlexLayout,
  QWidget
} from "@nodegui/nodegui";
import { QStatusBar } from "./index";

const win = new QMainWindow();
const rootView = new QWidget();
rootView.setObjectName("root");
rootView.setLayout(new FlexLayout());

const statusBar = new QStatusBar();
statusBar.setInlineStyle("align-self:'stretch';");

const button = new QPushButton();
button.setText("Push Push Push!");
button.addEventListener("clicked", () => {
  statusBar.showMessage(`hello ${Date.now()}`, 1000);
});

if (rootView.layout) {
  rootView.layout.addWidget(button);
  rootView.layout.addWidget(statusBar);
}

win.setCentralWidget(rootView);
win.setStyleSheet(`
  #root {
    flex: 1;
    height: '100%';
    align-items: 'center';
    justify-content: 'space-around';
  }
`);
win.setWindowTitle("NodeGUI Demo");
win.resize(400, 700);
win.show();

(global as any).win = win; // To prevent win from being garbage collected.
