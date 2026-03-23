*The very first line must be italicized and read: This project has been created as part
of the 42 curriculum by mramaros and ialrandr.*

# Push_Swap

## Description

**Push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a list of integers stored in a stack called **stack a**, using a second auxiliary stack **stack b**, with the minimum number of allowed operations.

The allowed operations are:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top 2 elements of stack a |
| `sb` | Swap the top 2 elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of stack b to stack a |
| `pb` | Push top of stack a to stack b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

The program must output the smallest sequence of operations that sorts stack a in ascending order.

---

## Instructions

### Compilation

```bash
make        # Compile push_swap
make bonus  # Compile checker (bonus)
make clean  # Remove object files
make fclean # Remove object files and binaries
make re     # Recompile everything
```

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers>
```

**Strategy flags (optional):**
- `--simple` — Force the O(n²) algorithm
- `--medium` — Force the O(n√n) algorithm
- `--complex` — Force the O(n log n) algorithm
- `--adaptive` — Use the adaptive algorithm based on disorder (default if no flag given)

**Benchmark flag (optional):**
- `--bench` — Print benchmark info to stderr (disorder %, strategy used, total ops, per-op counts)

**Examples:**

```bash
# Basic sort
./push_swap 2 1 3 6 5 8

# Count operations on 5 numbers
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Force complex algorithm and verify with checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG

# Large input with benchmark
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt)
cat bench.txt

# Error handling
./push_swap 0 one 2 3     # Error: non-integer argument
./push_swap 3 2 3         # Error: duplicate values
```

### Checker (bonus)

```bash
./checker <integers>
# Then type operations line by line, end with Ctrl+D
# Outputs OK if stack a is sorted and stack b is empty, KO otherwise
```

---

## Algorithms

### Disorder metric

Before sorting, the program computes a **disorder score** between 0 and 1 using the number of inversions in stack a:

```
disorder = (number of inverted pairs) / (total pairs)
```

A disorder of 0 means already sorted; 1 means fully reversed. This score is used by the adaptive algorithm to select the best strategy at runtime.

---

### 1. Simple algorithm — O(n²)

<span style="color:orange">**Strategy:** Selection sort adaptation — min extraction.</span>

At each step, the minimum element of stack a is located, rotated to the top (using `ra` or `rra` depending on which direction costs fewer operations), then pushed to stack b with `pb`. Once all elements are in stack b, they are pushed back to stack a with `pa` in order.

**Complexity:** O(n²) operations — for each of the n elements, up to n/2 rotations are needed to bring the minimum to the top.

**Used when:** `--simple` flag, or in adaptive mode when `n < 20` or `disorder < 0.2`.

---

### 2. Medium algorithm — O(n√n)

<span style="color:orange">**Strategy:** Chunk-based sorting.</span>

Elements are assigned rank indices (0 to n-1). They are then divided into chunks of size √n. Elements belonging to each chunk are pushed to stack b in order, rotating stack a as needed to find them efficiently. Once all elements are in stack b (sorted by chunks), they are pushed back to stack a from largest to smallest rank, again using rotations to bring each target element to the top.

**Complexity:** O(n√n) operations — n elements divided into √n chunks, each requiring O(√n) average rotations.

**Used when:** `--medium` flag, or in adaptive mode when `5 < n ≤ 100` or `0.2 ≤ disorder ≤ 0.5`.

---

### 3. Complex algorithm — O(n log n)

---

### 4. Adaptive algorithm (default)

The adaptive strategy measures the disorder and the input size before choosing the most appropriate method:

| Condition | Strategy used | Complexity |
|-----------|--------------|------------|
| `n ≤ 5` | Optimised hardcoded sort | O(1) |
| `n < 20` or `disorder < 0.2` | Simple (selection sort) | O(n²) |
| `5 < n ≤ 100` or `0.2 ≤ disorder ≤ 0.5` | Medium (chunk sort) | O(n√n) |
| `n > 100` and `disorder > 0.5` | Complex (radix sort) | O(n log n) |

**Rationale for thresholds:**
- Below 20 elements or very low disorder, the overhead of complex strategies is not worth it; the simple algorithm is fast enough and generates fewer operations in practice.
- For medium-sized inputs or medium disorder, chunk-based sorting achieves a good balance between operation count and implementation simplicity.
- For large, highly disordered inputs, radix sort's guaranteed O(n log n) behaviour ensures the best performance at scale.

---

## Performance

| Input size | Minimum (pass) | Good | Excellent | Our result |
|------------|---------------|------|-----------|------------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops | ~843 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops | ~8000 ops |

---

## Contributions

| Login | Contributions |
|-------|--------------|
| `mramaros` | Medium algorithm (chunk sort), disorder metric, adaptive strategy, benchmark output, simple optimised |
| `ialrandr` | Complex algorithm (radix sort), parsing, stack operations, checker (bonus), utils, simple algorithm |

---

## Resources

-[push_swap visualizer](https://push-swap42-visualizer.vercel.app/)
-[tutorial complixity](https://www.youtube.com/watch?v=OaG81sDEpVk)
-[stack learning](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

### AI usage

Claude (Anthropic) was used during this project for the following tasks:
- Helping understand the radix sort adaptation to the push_swap stack model
- Generating and reviewing the README structure and content
- Explaining algorithmic complexity in the context of push_swap operations

All code was written, reviewed, and fully understood by both learners before submission.
