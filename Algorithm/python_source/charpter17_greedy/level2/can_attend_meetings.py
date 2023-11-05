# coding=utf-8

class CanAttendMeetings:
    def canAttendMeetings(self, intervals):
        # 根据会议开始时间排序
        intervals.sort(key=lambda x: x[0])
        return all(intervals[i - 1][1] <= intervals[i][0] for i in range(1, len(intervals)))


if __name__ == '__main__':
    intervals = [[0, 30], [5, 10], [15, 20]]
    canAttendMeetings = CanAttendMeetings()
    print canAttendMeetings.canAttendMeetings(intervals)
