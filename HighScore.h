#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H

#include <vector>
#include <string>

class HighScoreManager {
public:
    HighScoreManager(const std::string& filename);
    ~HighScoreManager();

    void saveHighScores();
    // Thêm điểm mới, sau đó cập nhật danh sách (sắp xếp giảm dần, giữ tối đa 5 lượt)
    void addScore(int score);
    // Lấy danh sách điểm cao
    const std::vector<int>& getHighScores() const { return highScores; }

private:
    std::string fileName;
    std::vector<int> highScores;
};

#endif //HIGHSCORE_H

