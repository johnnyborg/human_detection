#ifndef HUMAN_DETECT_RECTANGLE
#define HUMAN_DETECT_RECTANGLE

#define ALLOWED_OFFSET 70

#include "opencv2/video/tracking.hpp"

using namespace cv;

class Rectangle
{
    public:
        Rectangle(const Rect &rect, int id);

        int getLastSeenTick();
        int accuracy();

        bool withinOffset(const Rect &rect);
        void adjustPosition(const Rect &rect);

        void registerTick(int tick, bool seen);

        int getId();

        Point tl;
        Point br;

    private:
        int lastTick, firstTick, seenTicks, missedTicks, id;
};

#endif