# Problem Statement
In a multiplayer battleground game, there are up to 4 players in each team, and the game supports a maximum of `n` teams competing simultaneously. Each player in the team has eliminated a certain number of opponents during the game, and the goal is to determine the potential winning teams.

Your manager has tasked you with designing an algorithm that identifies all potential winning teams based on the following criteria:

1. Teams with the highest total eliminations are considered first.
2. If multiple teams have the same highest total, compare their highest individual eliminations.
3. If teams have both the same total **AND** the same highest individual eliminations, all such teams should be included in the result.

## Input Format
- `n`: Number of teams (1 <= `n` <= 10^3).
- A list of `n` teams, where:
  - Each team has 1 to 4 players.
  - Each player has an integer representing their eliminations.

## Output Format
- Return a list containing details of potential winning teams:
  - Each element should contain: `{team_index, total_eliminations, highest_individual_elimination}`.
  - Team index should be 1-based.
  - Return multiple teams if they tie on both criteria.

## Example 1
**Input:**
```plaintext
teams = [
    [5, 2, 1, 3],  // Team 1: 4 players
    [4, 0, 8],     // Team 2: 3 players
    [2, 2, 3, 4]   // Team 3: 4 players
]
```

**Output:**
```plaintext
[{2, 12, 8}] // Only Team 2 wins
```

**Explanation:**
- Team 1: Total = 11, Highest = 5  
- Team 2: Total = 12, Highest = 8  
- Team 3: Total = 11, Highest = 4  

Team 2 wins with the highest total.

## Example 2
**Input:**
```plaintext
n = 4
teams = [
    [3, 3, 4],   // Team 1
    [5, 2, 3],   // Team 2
    [4, 3, 3],   // Team 3
    [5, 3, 2],   // Team 4
]
```

**Output:**
```plaintext
[{2, 10, 5}, {4, 10, 5}] // Teams 2 and 4
```

## Constraints
1. `1 <= n <= 10^3` (number of teams).
2. `1 <= team size <= 4` (players per team).
3. `0 <= eliminations <= 10^5` (per player).

## Hints
- Use some sorting technique to sort the teams based on the total eliminations and highest individual eliminations.
