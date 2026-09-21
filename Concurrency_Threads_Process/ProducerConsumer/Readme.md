C++ Threads + Shared Data Concept 

When multiple threads share data (like queue):

- You must protect shared data using:
    - `std::mutex`
- You use:
    - `std::condition_variable` for coordination (wait/notify)

Shared objects must be **common across all files**:

```
std::queue<int>q;
std::mutexmtx;
std::condition_variablecv;
```

---

# 🔐 2. Why same mutex is required

- Mutex protects shared resource
- If producer & consumer use different mutex → ❌ data race / no synchronization

✔ Correct:

Same `mtx` shared by all threads

---

# 📢 3. `condition_variable` flow (VERY IMPORTANT)

## Consumer flow:

```
unique_lock<mutex>lock(mtx);
cv.wait(lock,condition);
```

### Internally happens:

1. Lock mutex
2. Check condition
3. If false:
    - unlock mutex
    - sleep
4. On notify:
    - wake up
    - re-lock mutex
    - re-check condition
5. Continue after `wait()`

---

## Key point:

- `notify_one()` does NOT immediately run consumer
- It only wakes thread (makes it runnable)

Execution order depends on OS scheduler

---

# ⚙️ 4. Why output is not strictly alternating

Example:

```
Produced 1
Produced 2
...
Consumed 1  (later)
```

Reason:

- Thread scheduling is not controlled
- Producer may keep CPU and finish loop
- Consumer runs later

👉 `condition_variable` does NOT guarantee ordering

---

# 🧠 5. `extern` concept

```
externintx;
```

Means:

> "This variable exists somewhere else"
> 

### Rules:

| Type | Meaning |
| --- | --- |
| `int x;` | definition (memory created) |
| `extern int x;` | declaration only |

---

## Why needed in multi-file programs

- Avoid duplicate variables
- Share same object across files

---

## Correct structure:

### shared.cpp (definition)

```
std::mutexmtx;
std::queue<int>q;
std::condition_variablecv;
```

### other files (declaration)

```
extern std::mutexmtx;
extern std::queue<int>q;
extern std::condition_variablecv;
```

---

# 📁 6. Do we need `.h` file?

❌ Not required

✔ But recommended

Without `.h`:

- You manually repeat `extern` in every file

With `.h`:

- Clean
- Maintainable
- Standard practice

---

# 🧩 7. Compilation command

```
g++ main.cpp producer.cpp consumer.cpp shared.cpp-o app-pthread
```

### `pthread` is required because:

- enables thread support
- links pthread library
- required for mutex, thread, condition_variable

---

# ⚠️ If `pthread` missing:

Possible errors:

- undefined reference to `pthread_create`
- threading issues

---

# 📂 8. Compile many files easily

## Option 1: wildcard

```
g++ *.cpp-o app-pthread
```

---

## Option 2: Makefile (best practice)

### File name must be:

```
Makefile
```

---

### Simple Makefile:

```
app: *.cpp
	g++ *.cpp -o app -pthread
```

⚠ TAB is required before command

---

### Run:

```
make
./app
```

---

# ⚙️ 9. Large project compilation (advanced idea)

Step 1: compile

```
g++-c file.cpp
```

Step 2: link

```
g++ *.o-o app-pthread
```

---

# 🧾 FINAL SUMMARY

### Core rules:

- Same mutex must be shared across threads
- `cv.wait()` unlocks + sleeps + re-locks automatically
- `notify_one()` only wakes thread, not immediate execution
- `extern` = declaration, not definition
- `.h` file is optional but recommended
- Use `pthread` for multithreading
- Use `Makefile` or `.cpp` instead of listing files manually