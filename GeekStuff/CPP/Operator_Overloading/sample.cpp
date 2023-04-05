#include<iostream>
#include<list>

using namespace std;

class YoutubeChannel {
public:
    int subscribers;
    string name;

public:
    YoutubeChannel(int subs, string channelName) {
        this->subscribers = subs;
        this->name = channelName;
    }

    /*
    We can not create an operator function like this because the first parameter
    of the function must be the the class object where in this case it is not.
    So if we try to invoke this function, we would get error.
    */
    int operator<<(ostream& COUT) {
        COUT << "Channel name: " << this->name << endl;
    }

    /*
    This is required explicitly because we use remove function of list(library).
    Without this overloading, the remove function is not able to compare the type
    YoutubeChannel at the time of remove operation.
    */
    bool operator==(const YoutubeChannel& channel) const{
        return this->name == channel.name;
    }
};

class ChannelList {
public:
    list<YoutubeChannel> myChannelList;

public:
    void operator+(YoutubeChannel& channel) {
        this->myChannelList.push_back(channel);
    }
    void operator-(YoutubeChannel& channel) {
        this->myChannelList.remove(channel);
    }
};

// '&' is overloaded to print same like cout.
ostream& operator&(ostream& COUT, YoutubeChannel& channel) {
    COUT << "Channel name: " << channel.name << endl;
    COUT << "Subscribers: " << channel.subscribers << endl;
    return COUT;
}

ostream& operator&(ostream& COUT, ChannelList& channelList) {
    for(auto itr : channelList.myChannelList) {
        COUT & itr;
    }
    return COUT;
}

// Overloaded operator to return the sum of the subscribers
// return type is integer.
int operator+(YoutubeChannel& channel1, YoutubeChannel& channel2) {
    return channel1.subscribers + channel2.subscribers;
}

int main() {
    YoutubeChannel myChannel1 = YoutubeChannel(10000, "DSA_Tutor");
    YoutubeChannel myChannel2 = YoutubeChannel(50000, "LLD_Tutor");
    cout << "Below channels are created" << endl;
    cout & myChannel1 & myChannel2;

    cout << "Add all the channels to your list. Currently the List has below channels" << endl;

    ChannelList channelList;
    channelList + myChannel1;
    channelList + myChannel2;

    cout & channelList;

    cout << "Going to remove myChannel1 from the list" << endl;
    channelList - myChannel2;
    cout & channelList;
}