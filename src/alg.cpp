// Copyright 2021 NNTU-CS
int nPairs1(int* arr, int len, int value) {
int n = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) n++;
}
}
return n;
}
int nPairs2(int* arr, int len, int value) {
int n = 0;
int q = len;
int r = len - 1;
for (int q = len - 1; arr[q] > value; q--) r--;
for (int i = 0; i <= len; i++) {
if (arr[i] > value / 2) break;
for (int j = r; j > i; j--) {
if (arr[i] + arr[j] == value) {
n++;
}
if (arr[i] + arr[j] < value) break;
}
}
return n;
}
int nPairs3(int* arr, int len, int value) {
int n = 0;
int q = len - 1;
for (int i = 0; i < len - 1; i++) {
bool result = false;
int start = i + 1;
int mid = (start + q) / 2;
while (start <= q) {
if (arr[mid] == value - arr[i]) {
n++;
result = true;
break;
}
else if (arr[mid] > value - arr[i]) {
q = mid - 1;
}
else if (arr[mid] < value - arr[i]) {
start = mid + 1;
}
mid = (start + q) / 2;
}
int temp1 = mid;
int temp2 = mid;
if (result == true) {
while (arr[temp1 - 1] == arr[mid] && temp1 - 1 != i) {
n++;
temp1--;
}
while (arr[temp2 + 1] == arr[mid]) {
n++;
temp2++;
}
}
}
return n;
}
