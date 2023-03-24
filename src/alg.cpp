// Copyright 2021 NNTU-CS
// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len && arr[i] + arr[j] <= value; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
    if (arr[i] + arr[i + 1] > value) return count;
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int last = len;
    int first = i;
    while (first < last - 1) {
      int mid = (first + last) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        int middle = mid + 1;
        while (arr[i] + arr[middle] == value && middle < last) {
          count++;
          middle++;
        }
        middle = mid - 1;
        while (arr[i] + arr[middle] == value && middle > first) {
          count++;
          middle--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        last = mid;
      } else {
        first = mid;
      }
    }
  }
  return count;
}

