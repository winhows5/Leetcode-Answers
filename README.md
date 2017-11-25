# Leetcode-Answers

Some different answers about Leetcode algorithm problems.

The answers sort as time complexity.

### Special Instructions

There is a piece of code in many of the answers:

```
static int x = [](){
  std:ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
 }()
```

It's a way to increase the running speed which has nothing to do with the algorithm. In more detail, 'std:ios::sync_with_stdio(false)' would cancel the input / output buffer of iostream, and 'cin.tie(NULL)' would remove the binding between 'cin' and 'cout'. Both of them will save running time, making the efficiency of 'cin / cout' is almost the same as 'scanf / printf'.
