#pragma once

#include <nodegui/core/NodeWidget/nodewidget.h>

#include <QtWebEngineWidgets/QWebEngineView>

class NWebEngineView : public QWebEngineView, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QWebEngineView)
 public:
  using QWebEngineView::QWebEngineView;

  void connectWidgetSignalsToEventEmitter() {
    // Qt Connects: Implement all signal connects here
    QObject::connect(this, &QWebEngineView::loadFinished, [=](bool ok) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call(
          {Napi::Value::From(env, "loadFinished"), Napi::Value::From(env, ok)});
    });
    QObject::connect(this, &QWebEngineView::loadProgress, [=](int progress) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call({Napi::Value::From(env, "loadProgress"),
                             Napi::Value::From(env, progress)});
    });
    QObject::connect(this, &QWebEngineView::loadStarted, [=]() {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call({Napi::Value::From(env, "loadStarted")});
    });
    QObject::connect(this, &QWebEngineView::selectionChanged, [=]() {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call({Napi::Value::From(env, "selectionChanged")});
    });
    QObject::connect(this, &QWebEngineView::urlChanged, [=](QUrl url) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call(
          {Napi::Value::From(env, "urlChanged"),
           Napi::Value::From(env, url.toString().toStdString())});
    });
    QObject::connect(this, &QWebEngineView::titleChanged, [=](QString title) {
      Napi::Env env = this->emitOnNode.Env();
      Napi::HandleScope scope(env);
      this->emitOnNode.Call({Napi::Value::From(env, "titleChanged"),
                             Napi::Value::From(env, title.toStdString())});
    });
  }
};
