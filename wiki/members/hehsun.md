# @hehsun

## Stats
| Total | Easy | Medium | Hard |
|-------|------|--------|------|
| 2 | 1 | 1 | 0 |

Languages: C++ (0001), C (0189)

| Pattern | Count |
|---------|-------|
| [complement-lookup](../patterns/complement-lookup.md) | 1 |
| [array-reversal](../patterns/array-reversal.md) | 1 |
| [two-pointers](../patterns/two-pointers.md) | 1 |

## Strengths
- Writes clear notes on edge cases: explained why looking up before inserting handles both self-pairing and duplicates ([0001](../problems/0001-two-sum.md)).
- Reviews their own code for robustness: spotted that the class-member map would carry state between calls ([0001](../problems/0001-two-sum.md)).
- Goes for the optimal in-place solution and handles edge cases up front: three-reversal rotation in O(1) space, with `k %= n` so `k >= n` works ([0189](../problems/0189-rotate-array.md)).

## Weaknesses
_(Not enough data yet.)_

## Recurring Mistake Patterns
_(None yet.)_

## Review Queue
| Problem | Last attempt | Result | Next review | Reason |
|---------|--------------|--------|-------------|--------|
| [0001 Two Sum](../problems/0001-two-sum.md) | 2026-10-16 | AC | 2026-10-23 | First AC; `used_hint` left blank, assumed no hint (+7 days) |
| [0189 Rotate Array](../problems/0189-rotate-array.md) | 2026-10-16 | AC | 2026-10-23 | First AC (20m); `used_hint` left blank, assumed no hint (+7 days) |
