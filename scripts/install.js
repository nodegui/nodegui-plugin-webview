#!/usr/bin/env node

const { setupArtifact } = require("@nodegui/artifact-installer");
const {
  miniQt,
  useCustomQt,
  qtHome
} = require("@nodegui/nodegui/config/qtConfig");
const os = require("os");
const path = require("path");
const fs = require("fs");

const checkIfExists = fullPath => {
  return () => fs.existsSync(fullPath);
};

function getMiniQtWebviewArtifacts() {
  if (miniQt.version !== "5.14.1") {
    throw new Error(
      `Unsupported miniqt version ${miniQt.version}. Please raise an issue ticket on the plugin repo. This plugin only supports miniQt version 5.14.1, the author of the plugin will need to update the download links.`
    );
  }

  switch (os.platform()) {
    case "darwin": {
      return {
        artifacts: [
          {
            name: "Qt WebEngine",
            link: `https://download.qt.io/online/qtsdkrepository/mac_x64/desktop/qt5_5141/qt.qt5.5141.qtwebengine.clang_64/5.14.1-0-202001241000qtwebengine-MacOS-MacOS_10_13-Clang-MacOS-MacOS_10_13-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(
                qtHome,
                "lib",
                "cmake",
                "Qt5WebEngine",
                "Qt5WebEngineConfig.cmake"
              )
            )
          },
          {
            name: "Qt Declarative",
            link: `https://download.qt.io/online/qtsdkrepository/mac_x64/desktop/qt5_5141/qt.qt5.5141.clang_64/5.14.1-0-202001241000qtdeclarative-MacOS-MacOS_10_13-Clang-MacOS-MacOS_10_13-X86_64.7z`,
            skipSetup: checkIfExists(path.resolve(qtHome, "bin", "qmlmin"))
          },
          {
            name: "Qt WebChannel",
            link: `https://download.qt.io/online/qtsdkrepository/mac_x64/desktop/qt5_5141/qt.qt5.5141.clang_64/5.14.1-0-202001241000qtwebchannel-MacOS-MacOS_10_13-Clang-MacOS-MacOS_10_13-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(
                qtHome,
                "lib",
                "cmake",
                "Qt5WebChannel",
                "Qt5WebChannelConfig.cmake"
              )
            )
          },
          {
            name: "Qt Location",
            link: `https://download.qt.io/online/qtsdkrepository/mac_x64/desktop/qt5_5141/qt.qt5.5141.clang_64/5.14.1-0-202001241000qtlocation-MacOS-MacOS_10_13-Clang-MacOS-MacOS_10_13-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(
                qtHome,
                "lib",
                "cmake",
                "Qt5Location",
                "Qt5LocationConfig.cmake"
              )
            )
          }
        ]
      };
    }
    case "win32": {
      return {
        artifacts: [
          {
            name: "Qt WebEngine",
            link: `https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt5_5141/qt.qt5.5141.qtwebengine.win64_msvc2017_64/5.14.1-0-202001240957qtwebengine-Windows-Windows_10-MSVC2017-Windows-Windows_10-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(
                qtHome,
                "lib",
                "cmake",
                "Qt5WebEngine",
                "Qt5WebEngineConfig.cmake"
              )
            )
          },
          {
            name: "Qt Declarative",
            link: `https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt5_5141/qt.qt5.5141.win64_msvc2017_64/5.14.1-0-202001240957qtdeclarative-Windows-Windows_10-MSVC2017-Windows-Windows_10-X86_64.7z`,
            skipSetup: checkIfExists(path.resolve(qtHome, "bin", "Qt5Qml.dll"))
          },
          {
            name: "Qt WebChannel",
            link: `https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt5_5141/qt.qt5.5141.win64_msvc2017_64/5.14.1-0-202001240957qtwebchannel-Windows-Windows_10-MSVC2017-Windows-Windows_10-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(qtHome, "bin", "Qt5WebChannel.dll")
            )
          },
          {
            name: "Qt Location",
            link: `https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt5_5141/qt.qt5.5141.win64_msvc2017_64/5.14.1-0-202001240957qtlocation-Windows-Windows_10-MSVC2017-Windows-Windows_10-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(qtHome, "bin", "Qt5Location.dll")
            )
          }
        ]
      };
    }
    case "linux": {
      return {
        artifacts: [
          {
            name: "Qt WebEngine",
            link: `https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt5_5141/qt.qt5.5141.qtwebengine.gcc_64/5.14.1-0-202001240953qtwebengine-Linux-RHEL_7_6-GCC-Linux-RHEL_7_6-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(qtHome, "bin", "Qt5Location.dll")
            )
          },
          {
            name: "Qt Declarative",
            link: `https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt5_5141/qt.qt5.5141.gcc_64/5.14.1-0-202001240953qtdeclarative-Linux-RHEL_7_6-GCC-Linux-RHEL_7_6-X86_64.7z`,
            skipSetup: checkIfExists(path.resolve(qtHome, "bin", "qmlmin"))
          },
          {
            name: "Qt WebChannel",
            link: `https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt5_5141/qt.qt5.5141.gcc_64/5.14.1-0-202001240953qtwebchannel-Linux-RHEL_7_6-GCC-Linux-RHEL_7_6-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(
                qtHome,
                "lib",
                "cmake",
                "Qt5WebChannel",
                "Qt5WebChannelConfig.cmake"
              )
            )
          },
          {
            name: "Qt Location",
            link: `https://download.qt.io/online/qtsdkrepository/linux_x64/desktop/qt5_5141/qt.qt5.5141.gcc_64/5.14.1-0-202001240953qtlocation-Linux-RHEL_7_6-GCC-Linux-RHEL_7_6-X86_64.7z`,
            skipSetup: checkIfExists(
              path.resolve(
                qtHome,
                "lib",
                "cmake",
                "Qt5Location",
                "Qt5LocationConfig.cmake"
              )
            )
          }
        ]
      };
    }
  }
}

async function setupQt() {
  const webviewArtifacts = getMiniQtWebviewArtifacts();
  return Promise.all(
    webviewArtifacts.artifacts.map(async artifact =>
      setupArtifact({
        outDir: miniQt.setupDir,
        id: "nodegui-mini-qtwebview", //cache-id
        displayName: `${artifact.name} for Minimal Qt: ${miniQt.version} installation`,
        downloadLink: artifact.link,
        skipSetup: artifact.skipSetup
      })
    )
  );
}

if (!useCustomQt) {
  console.log(`Minimal Qt ${miniQt.version} setup:`);

  setupQt().catch(err => {
    console.error(err);
    process.exit(1);
  });
} else {
  console.log(
    `CustomQt detected at ${qtHome} . Hence, skipping Mini Qt installation...`
  );
}
