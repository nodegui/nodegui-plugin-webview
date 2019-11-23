#pragma once

#include <nodegui/core/NodeWidget/nodewidget.h>

#include <QWebEngineView>

class NWebEngineView : public QWebEngineView, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QWebEngineView)
 public:
  using QWebEngineView::QWebEngineView;
};
