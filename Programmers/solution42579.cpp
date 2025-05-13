/*
 * Link : https://school.programmers.co.kr/learn/courses/30/lessons/42579
 *
 * Solution : 가장 많은 장르 중 가장 많이 재생된 노래를 수록. 장르당 노래도 최대 2개
 *  만약 같다면 고유 번호가 낮은 노래를 수록
 *
 *  Genres[i] : 고유 번호가 i 인 노래의 장르
 *  Plays[i] : 고유 번호가 i 인 노래의 재생 횟수
 *
 *  1 <= Genres.Size() == Plays.Size() <= 10000
 *  장르의 종류 < 100
 *  장르에 곡이 1개라면 하나만 선택
 *  장르마다 재생된 회수는 다름
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct MusicInfo
{
    string GenreName;
    
    int PlayNumTotal = 0;
    
    pair<int, int> FirstIndexNPlay = make_pair(-1, 0);
    pair<int, int> SecondIndexNPlay = make_pair(-1, 0);
};

bool CompareTotalNum(MusicInfo MusicInfoA, MusicInfo MusicInfoB)
{
    return MusicInfoA.PlayNumTotal > MusicInfoB.PlayNumTotal;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<MusicInfo> MusicInfos;

    for (int i = 0; i < genres.size(); i++)
    {
        bool bIsFind = false;
        
        for (auto& CachedMusicInfo : MusicInfos)
        {
            if (CachedMusicInfo.GenreName == genres[i])
            {
                bIsFind = true;
                CachedMusicInfo.PlayNumTotal += plays[i];

                if (CachedMusicInfo.FirstIndexNPlay.second < plays[i])
                {
                    CachedMusicInfo.SecondIndexNPlay = CachedMusicInfo.FirstIndexNPlay;
                    
                    CachedMusicInfo.FirstIndexNPlay.first = i;
                    CachedMusicInfo.FirstIndexNPlay.second = plays[i];
                }
                else if (CachedMusicInfo.SecondIndexNPlay.second < plays[i])
                {
                    CachedMusicInfo.SecondIndexNPlay.first = i;
                    CachedMusicInfo.SecondIndexNPlay.second = plays[i];
                }
                break;
            }
        }

        if (!bIsFind)
        {
            MusicInfo LocalMusicInfo;
            
            LocalMusicInfo.GenreName = genres[i];
            LocalMusicInfo.PlayNumTotal += plays[i];

            LocalMusicInfo.FirstIndexNPlay.first = i;
            LocalMusicInfo.FirstIndexNPlay.second = plays[i];

            MusicInfos.push_back(LocalMusicInfo);
        }
    }

    sort(MusicInfos.begin(), MusicInfos.end(), CompareTotalNum);
    
    vector<int> answer;
    for (const auto& MusicInfo : MusicInfos)
    {
        answer.push_back(MusicInfo.FirstIndexNPlay.first);
        if (MusicInfo.SecondIndexNPlay.first >= 0)
        {
            answer.push_back(MusicInfo.SecondIndexNPlay.first);
        }
    }
    
    return answer;
}
