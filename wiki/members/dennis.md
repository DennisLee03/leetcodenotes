# @dennis

## Stats
| Total | Easy | Medium | Hard |
|-------|------|--------|------|
| 1 | 1 | 0 | 0 |

Languages: C++ (0217)

| Pattern | Count |
|---------|-------|
| [complement-lookup](../patterns/complement-lookup.md) | 1 |

Notes written but not yet ingested: 0027 Remove Element, 0088 Merge Sorted Array (both still have `YYYY-MM-DD` dates and empty Notes sections).

## Strengths
- Uses problems to learn the language: the [0217](../problems/0217-contains-duplicate.md) note covers parameter passing, `vector` basics, and a `set` vs `unordered_set` comparison including rehash and load factor, which goes well beyond the solution itself.
- Picks the right data structure on the first try: hash set for membership ([0217](../problems/0217-contains-duplicate.md)).

## Weaknesses
_(Not enough data yet.)_

## Recurring Mistake Patterns
- Complexity details: in [0217](../problems/0217-contains-duplicate.md), wrote `set` insert/delete as "O(log n) + rebalance" (rebalancing is already inside the O(log n)) and left out "amortized" for `unordered_set` insert. One data point so far.

## Review Queue
| Problem | Last attempt | Result | Next review | Reason |
|---------|--------------|--------|-------------|--------|
| [0217 Contains Duplicate](../problems/0217-contains-duplicate.md) | 2026-10-11 | AC | 2026-10-18 (overdue) | First AC without hints (+7 days) |
