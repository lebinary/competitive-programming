import sys

input = sys.stdin.readline

"""
1. how would you test this?
- unit test: testing the core logic
- integration test: testing how "server" interacts with other components in the system
- e2e test: test the full authentication flow as a user, should not be done to frequently as this process is costly

2. how would you prepare this for production?
- add mutex, 1-on-1 mapping for lock and the tokenId, to ensure consistency
- placed this in an isolated authentication/authorization server, do stateless authen/author - after authen/author, user received a jwt token and use that for subsequent requests
- handle some other edge cases: timestamp in the past, cleanup expired tokens, etc...

"""


class AuthenticationManager:
    def __init__(self, timeToLive: int):
        self.ttl = timeToLive
        self.server = {}

    # O(1)
    def generate(self, tokenId: str, currentTime: int) -> None:
        endTime = currentTime + self.ttl
        self.server[tokenId] = endTime

    # O(1)
    def renew(self, tokenId: str, currentTime: int) -> None:
        if self.server.get(tokenId, 0) > currentTime:
            endTime = currentTime + self.ttl
            self.server[tokenId] = endTime

    # O(n)
    def countUnexpiredTokens(self, currentTime: int) -> int:
        return sum(1 for endTime in self.server.values() if endTime > currentTime)


def main():
    n = int(input())
    manager = None
    results = []

    for _ in range(n):
        line = input().split()
        cmd = line[0]

        if cmd == "AuthenticationManager":
            ttl = int(line[1])
            manager = AuthenticationManager(ttl)
            results.append("null")
        elif cmd == "generate":
            tokenId, currentTime = line[1], int(line[2])
            if manager:
                manager.generate(tokenId, currentTime)
            results.append("null")
        elif cmd == "renew":
            tokenId, currentTime = line[1], int(line[2])
            if manager:
                manager.renew(tokenId, currentTime)
            results.append("null")
        elif cmd == "countUnexpiredTokens":
            currentTime = int(line[1])
            if manager:
                res = manager.countUnexpiredTokens(currentTime)
                results.append(str(res))

    print("\n".join(results))


if __name__ == "__main__":
    main()
