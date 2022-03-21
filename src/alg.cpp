// Copyright 2021 NNTU-CS
void serch(int *arr, int len) {
int t;
for (int i = 0; i < len - 1; i++) {
for (int j = 0; j < len - 1 - i; j++) {
if (arr[j] > arr[j + 1]) {
t = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = t;
}}}}  
int countPairs1(int *arr, int len, int value) {
int n = 0;
serch(arr, len);
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value){
n++;
}}}
return n;
}
int countPairs2(int *arr, int len, int value) {
int n = 0;
int i, j;
serch(arr, len);
i = 0;
j = len - 1;
while (i <= j) {
for (int t = i + 1; t <= j; t++) {
if(arr[i] + arr[t] == value && arr[i] < value && arr[t] < value) {
n++;
}}
i++;
for (int t = j - 1; t >= i; t--) {
if (arr[j] + arr[t] == value && arr[j] < value && arr[t] < value) {
n++;
}}
j--;
}
return n;
}
int countPairs3(int *arr, int len, int value) {
serch(arr, len);
int n = 0;
int s = 0;
while (arr[s] * 2 < value || s < len) {
s++;
}
for (int i = 0; i < s; i++) {
for (int j = s; j < len; j++) {
if (arr[i] + arr[j] == value) {
n++;
}}}
for (int i = s; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) {
n++;
}}}
return n;
}
