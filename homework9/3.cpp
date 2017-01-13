#include <iostream>
using namespace std;

/*Adapter pattern*/

//step 1: build abstract class MediaPlayer and advancedMediaPlayer
class MediaPlayer
{
  public:
    virtual void play(std::string audioType, std::string fileName) = 0;
};

class AdvancedMediaPlayer
{
  public:
    virtual void playVlc(std::string fileName) = 0;
    virtual void playMp4(std::string fileName) = 0;
};

//step 2: concret classes declares vlc and mp4 player
class VlcPlayer : public AdvancedMediaPlayer
{
  public:
    void playVlc(std::string fileName)
    {
        cout << "Playing vlc file. Name: " << fileName << endl;
    }
    void playMp4(std::string fileName)
    {
    }
};

class Mp4Player : public AdvancedMediaPlayer
{
  public:
    void playVlc(std::string fileName)
    {
    }
    void playMp4(std::string fileName)
    {
        cout << "Playing mp4 file. Name: " << fileName << endl;
    }
};

//step 3: adapter class which help audio player playing extra extension vlc and mp4
class MediaAdapter : public MediaPlayer
{
    AdvancedMediaPlayer *advancedMusicPlayer; 

  public:
    MediaAdapter(std::string audioType)
    {
        if (audioType == "vlc")
        {
            advancedMusicPlayer = new VlcPlayer;
        }
        else if (audioType == "mp4")
        {
            advancedMusicPlayer = new Mp4Player;
        }
    }

    void play(std::string audioType, std::string fileName)
    {
        if (audioType == "vlc")
        {
            advancedMusicPlayer->playVlc(fileName);
        }
        else if (audioType == "mp4")
        {
            advancedMusicPlayer->playMp4(fileName);
        }
    }
};

//step 4: Audio player implement MediaPlayer abstract class
class AudioPlayer : public MediaPlayer
{
    MediaAdapter *mediaAdapter;

  public:
    void play(std::string audioType, std::string fileName)
    {
        if (audioType == "mp3") 
        {
            cout << "Playing mp3 file. Name: " << fileName << endl;
        }

        //mediaAdapter is providing support to play other file formats
        else if (audioType == "vlc" || audioType == "mp4")
        {

            mediaAdapter = new MediaAdapter(audioType);
            mediaAdapter->play(audioType, fileName);
        }

        else
        {
            cout << "Invalid media. " << audioType << " format not supported" << endl;
        }
    }
};

//step 5: verify result
int main()
{
    AudioPlayer audioPlayer;
    audioPlayer.play("mp3", "beyond the horizon.mp3");
    audioPlayer.play("mp4", "alone.mp4");
    audioPlayer.play("vlc", "far far away.vlc");
    audioPlayer.play("avi", "mind me.avi");
    return 0;
}
