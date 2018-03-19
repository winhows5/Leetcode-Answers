# Leetcode-Answers

Some different answers about Leetcode algorithm problems.

The answers sort as time complexity.

### Special Instructions

There is a piece of code in many of the answers:

``` C++
static int x = [](){
  std:ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
 }()
```

It's a way to increase the running speed which has nothing to do with the algorithm. In more detail, `std:ios::sync_with_stdio(false)` would cancel the input / output buffer of iostream, and `cin.tie(NULL)` would remove the binding between `cin` and `cout`. Both of them will save running time, making the efficiency of `cin / cout` is almost the same as `scanf / printf`.

### Update 2018/03/19

Celebrate that I can solve it almost independently after 50 problems. What's more, I had beat 100.00% answers for several times (**Excited :)**).
