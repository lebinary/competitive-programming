# 475. Heaters

Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range.

Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.

Notice that all the heaters follow your radius standard, and the warm radius will be the same.

## Example 1:
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

## Example 2:
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.

## Example 3:
Input: houses = [1,5], heaters = [2]
Output: 3

## Constraints:
1 <= houses.length, heaters.length <= 3 * 10^4
1 <= houses[i], heaters[i] <= 10^9

## Thoughts:
- Asumptions: houses and heaters are sorted
- Facts:
  - At lease 1 house and 1 heater
  - Optimizing problem: Find smallest radius
- Ideas:
  Answer space is monotonic => Binary search
  Need to figure out the validator alg (Given radius `r`, check if it can cover all houses)
  - **Validator algorithm:**
    - two pointers, i for houses and j for heaters:
      for(j : 0 < heaters):
        while(i < house.length && house[i] in range(heater[j] - radius, heater[j] + radius)):
          i++
        if i >= house.length: return true
      return false
