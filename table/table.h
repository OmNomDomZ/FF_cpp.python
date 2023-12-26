#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <vector>
#include <utility>

template <typename T>
class Table {
private:
  std::vector<std::vector<T>> data;
  size_t rows;
  size_t columns;

public:
  Table(size_t rows, size_t columns) : rows(rows), columns(columns) {
    data.resize(rows, std::vector<T>(columns));
  }

  std::vector<T>& operator[](size_t index) {
    return data[index];
  }

  const std::vector<T>& operator[](size_t index) const {
    return data[index];
  }

  void Resize(size_t newRows, size_t newColumns) {
    data.resize(newRows, std::vector<T>(newColumns, T()));

    for (auto& row : data) {
      row.resize(newColumns, T());
    }

    rows = newRows;
    columns = newColumns;
  }

  std::pair<size_t, size_t> Size() const {
    return std::make_pair(rows, columns);
  }
};

#endif // TABLE_H
