import sys

input = sys.stdin.readline

class AuthenticationManager:
    def __init__(self, timeToLive):
        self.ttl = timeToLive
        self.server = {}

    def generate(self, tokenId, currentTime):
        self.server[tokenId] = currentTime + self.ttl

    def renew(self, tokenId, currentTime):
        if self.server.get(tokenId, 0) > currentTime:
            self.server[tokenId] = currentTime + self.ttl

    def countUnexpiredTokens(self, currentTime):
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
        elif cmd == "generate":
            tokenId, currentTime = line[1], int(line[2])
            manager.generate(tokenId, currentTime)
            results.append("null")
        elif cmd == "renew":
            tokenId, currentTime = line[1], int(line[2])
            manager.renew(tokenId, currentTime)
            results.append("null")
        elif cmd == "countUnexpiredTokens":
            currentTime = int(line[1])
            count = manager.countUnexpiredTokens(currentTime)
            results.append(str(count))
        else:
            raise ValueError(f"Unknown command: {cmd}")

    print("\n".join(results))


if __name__ == "__main__":
    main()
