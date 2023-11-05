# coding=utf-8

class PartitionLabels:
    def partitionLabels(self, s):
        last = [0] * 26
        for i, ch in enumerate(s):
            last[ord(ch) - ord("a")] = i

        partition = list()
        start = end = 0
        for i, ch in enumerate(s):
            end = max(end, last[ord(ch) - ord("a")])
            if i == end:
                partition.append(end - start + 1)
                start = end + 1
        return partition


if __name__ == '__main__':
    s = "ababcbacadefegdehijhklij"
    partitionLabels = PartitionLabels()
    print partitionLabels.partitionLabels(s)
