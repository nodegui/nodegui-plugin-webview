#pragma once

#include <nodegui/core/NodeWidget/nodewidget.h>

#include <QtWebChannel/QWebChannel>

#include "nodegui/core/Events/eventwidget.h"
#include "nodegui/core/Events/eventwidget_macro.h"

class DLL_EXPORT NWebChannel : public QWebChannel, public EventWidget {
  Q_OBJECT
  EVENTWIDGET_IMPLEMENTATIONS(QWebChannel)
 public:
  using QWebChannel::QWebChannel;

  void connectSignalsToEventEmitter() { }
};