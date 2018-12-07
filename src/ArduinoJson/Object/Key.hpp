// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

namespace ARDUINOJSON_NAMESPACE {

class Key {
 public:
  Key(const VariantSlot* slot) : _slot(slot) {}

  operator const char*() const {
    return c_str();
  }

  const char* c_str() const {
    return _slot ? _slot->key() : 0;
  }

  bool isNull() const {
    return _slot == 0 || _slot->key() == 0;
  }

  friend bool operator==(Key lhs, const char* rhs) {
    if (lhs.isNull()) return rhs == 0;
    return rhs ? !strcmp(lhs, rhs) : false;
  }

 private:
  const VariantSlot* _slot;
};
}  // namespace ARDUINOJSON_NAMESPACE
