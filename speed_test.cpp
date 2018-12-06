//
// Created by Keegan Millard on 2018-12-05.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <unordered_map>
#include <iomanip>

#include "Image.h"
#include "PGM.h"
#include "Alpha.h"

using namespace std;

const string destdir = "./out_images/";
const string srcdir = "./input_images/";

std::unordered_map<string,Image*> image_map;

void create(string filename) {
    Image *im = Image::create(srcdir+filename);
    if(image_map.find(filename) == image_map.end())
        image_map.insert( make_pair <string, Image*>((string)filename,(Image*)im));
    else
        delete im;
}

void write(const string &filename){
    Image *im = image_map[filename];
    im->write(destdir+filename);
}

void half_size(const string &filename){
    Image *im = image_map[filename];
    im->resize(0.5);
}

void double_size(const string &filename){
    Image *im = image_map[filename];
    im->resize(2.0);
}

void mirror(const string &filename){
    Image *im = image_map[filename];
    im->mirror();
}

void rotate90(const string &filename){
    Image *im = image_map[filename];
    im->rotate(90);
}

void rotate180(const string &filename){
    Image *im = image_map[filename];
    im->rotate(180);
}

void rotate270(const string &filename){
    Image *im = image_map[filename];
    im->rotate(270);
}

void min(int dir, const string &filename1, const string &filename2){
    Image *im1 = image_map[filename1];
    Image *im2 = image_map[filename1];
    im1->min(dir,*im2);
}

void max(int dir, const string &filename1, const string &filename2){
    Image *im1 = image_map[filename1];
    Image *im2 = image_map[filename1];
    im1->max(dir,*im2);
}

template<typename T>
void run_test(const string &name, int iter) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    for(int x = 0; x < iter; x++)
        T::test();

    auto duration =  high_resolution_clock::now() - start;
    std::cout << name << " x " << to_string(iter) << '\n';
    std::cout << "ms: " << std::setprecision(2) << std::fixed << (double) duration_cast<microseconds>(duration).count() / 1000 << '\n';
}

struct CreateSmallAlpha {

    static void test() {
//        create("j.alpha");
//        create("j_clean.alpha");
//        create("j_star.alpha");
//        create("p.alpha");
//        create("hi.alpha");
        create("feep.alpha");
//        create("luna_small.alpha");
        create("image10_small.alpha");
        create("image11_small.alpha");
        create("image15_small.alpha");

    }
};

struct CreateSmallPGM {

    static void test() {
//        create("hi.pgm");
        create("feep.pgm");
 //      create("my.pgm");
        create("image10_small.pgm");
        create("image11_small.pgm");
        create("image15_small.pgm");
    }
};

struct CreateLargePGM {

    static void test() {
        create("einstein.pgm");
        create("image10.pgm");
        create("image16.pgm");
        create("image17.pgm");
        create("image21.pgm");
        create("image23.pgm");
        create("image24.pgm");
        create("image26.pgm");
    }

};

struct CreateLargeAlpha {

    static void test() {
        create("einstein.alpha");
        create("image10.alpha");
        create("image16.alpha");
        create("image17.alpha");
        create("image21.alpha");
        create("image23.alpha");
        create("image24.alpha");
        create("image26.alpha");
    }

};

struct WriteSmallAlpha {

    static void test() {
//        create("j.alpha");
//        create("j_clean.alpha");
//        create("j_star.alpha");
//        create_and_write("p.alpha");
//        create("hi.alpha");
        write("feep.alpha");
//        write("luna_small.alpha");
        write("image10_small.alpha");
        write("image11_small.alpha");
        write("image15_small.alpha");

    }
};

struct WriteSmallPGM {

    static void test() {
//        create("j.pgm");
//        create("j_clean.pgm");
//        create("j_star.pgm");
//        create_and_write("p.pgm");
//        create("hi.pgm");
        write("feep.pgm");
//        write("luna_small.pgm");
        write("image10_small.pgm");
        write("image11_small.pgm");
        write("image15_small.pgm");

    }
};

struct WriteLargeAlpha {

    static void test() {
        write("einstein.alpha");
        write("image10.alpha");
        write("image16.alpha");
        write("image17.alpha");
        write("image21.alpha");
        write("image23.alpha");
        write("image24.alpha");
        write("image26.alpha");
    }

};

struct WriteLargePGM {

    static void test() {
        write("einstein.pgm");
        write("image10.pgm");
        write("image16.pgm");
        write("image17.pgm");
        write("image21.pgm");
        write("image23.pgm");
        write("image24.pgm");
        write("image26.pgm");
    }

};

struct Resize {

    static void test() {
        half_size("einstein.pgm");
        half_size("image10.pgm");
        half_size("image16.pgm");
        half_size("image17.pgm");
        half_size("image21.pgm");

        half_size("einstein.alpha");
        half_size("image10.alpha");
        half_size("image16.alpha");
        half_size("image17.alpha");
        half_size("image21.alpha");

        double_size("einstein.pgm");
        double_size("image10.pgm");
        double_size("image16.pgm");
        double_size("image17.pgm");
        double_size("image21.pgm");

        double_size("einstein.alpha");
        double_size("image10.alpha");
        double_size("image16.alpha");
        double_size("image17.alpha");
        double_size("image21.alpha");
    }

};

struct Mirror {

    static void test() {
        mirror("feep.pgm");
        mirror("image10_small.pgm");
        mirror("image11_small.pgm");
        mirror("image15_small.pgm");

        mirror("einstein.pgm");
        mirror("image10.pgm");
        mirror("image16.pgm");
        mirror("image17.pgm");
        mirror("image21.pgm");

        mirror("feep.alpha");
        mirror("image10_small.alpha");
        mirror("image11_small.alpha");
        mirror("image15_small.alpha");

        mirror("einstein.alpha");
        mirror("image10.alpha");
        mirror("image16.alpha");
        mirror("image17.alpha");
        mirror("image21.alpha");
    }

};

struct Rotate90 {

    static void test() {
        rotate90("feep.pgm");
        rotate90("image10_small.pgm");
        rotate90("image11_small.pgm");
        rotate90("image15_small.pgm");
        rotate90("einstein.pgm");
        rotate90("image10.pgm");
        rotate90("image16.pgm");
        rotate90("image17.pgm");
        rotate90("image21.pgm");
        rotate90("image23.pgm");
        rotate90("image24.pgm");
        rotate90("image26.pgm");

        rotate90("feep.alpha");
        rotate90("image10_small.alpha");
        rotate90("image11_small.alpha");
        rotate90("image15_small.alpha");
        rotate90("einstein.alpha");
        rotate90("image10.alpha");
        rotate90("image16.alpha");
        rotate90("image17.alpha");
        rotate90("image21.alpha");
        rotate90("image23.alpha");
        rotate90("image24.alpha");
        rotate90("image26.alpha");
    }

};

struct Rotate180 {

    static void test() {
        rotate180("feep.pgm");
        rotate180("image10_small.pgm");
        rotate180("image15_small.pgm");
        rotate180("einstein.pgm");
        rotate180("image10.pgm");
        rotate180("image16.pgm");
        rotate180("image17.pgm");
        rotate180("image21.pgm");
        rotate180("image23.pgm");
        rotate180("image24.pgm");
        rotate180("image26.pgm");

        rotate180("feep.alpha");
        rotate180("image10_small.alpha");
        rotate180("image15_small.alpha");
        rotate180("einstein.alpha");
        rotate180("image10.alpha");
        rotate180("image16.alpha");
        rotate180("image17.alpha");
        rotate180("image21.alpha");
        rotate180("image23.alpha");
        rotate180("image24.alpha");
        rotate180("image26.alpha");
    }

};

struct Rotate270 {

    static void test() {
        rotate270("feep.pgm");
        rotate270("image10_small.pgm");
        rotate270("image15_small.pgm");
        rotate270("einstein.pgm");
        rotate270("image10.pgm");
        rotate270("image16.pgm");
        rotate270("image17.pgm");
        rotate270("image21.pgm");
        rotate270("image23.pgm");
        rotate270("image24.pgm");
        rotate270("image26.pgm");

        rotate270("feep.alpha");
        rotate270("image10_small.alpha");
        rotate270("image15_small.alpha");
        rotate270("einstein.alpha");
        rotate270("image10.alpha");
        rotate270("image16.alpha");
        rotate270("image17.alpha");
        rotate270("image21.alpha");
        rotate270("image23.alpha");
        rotate270("image24.alpha");
        rotate270("image26.alpha");
    }

};

struct ImageMin {

    static void test() {

        min(Image::NW, "feep.alpha", "image10_small.alpha");
        min(Image::NE, "image26.alpha", "einstein.alpha");
        min(Image::SW, "image10.alpha", "image16.alpha");
        min(Image::SE, "image17.alpha", "image21.alpha");
        min(Image::NE, "image23.alpha", "image24.alpha");

        min(Image::NW, "feep.pgm", "image10_small.pgm");
        min(Image::NE, "image26.pgm", "einstein.pgm");
        min(Image::SW, "image10.pgm", "image16.pgm");
        min(Image::SE, "image17.pgm", "image21.pgm");
        min(Image::NW, "image23.pgm", "image24.pgm");

        min(Image::NW, "feep.alpha", "image10_small.pgm");
        min(Image::NE, "image26.alpha", "einstein.pgm");
        min(Image::SW, "image10.alpha", "image16.pgm");
        min(Image::SE, "image17.alpha", "image21.pgm");
        min(Image::SW, "image23.alpha", "image24.pgm");

        min(Image::NW, "feep.pgm", "image10_small.alpha");
        min(Image::NE, "image26.pgm", "einstein.alpha");
        min(Image::SW, "image10.pgm", "image16.alpha");
        min(Image::SE, "image17.pgm", "image21.alpha");
        min(Image::SE, "image23.pgm", "image24.alpha");

    }

};

struct ImageMax {

    static void test() {

        max(Image::NW, "feep.alpha", "image10_small.alpha");
        max(Image::NE, "image26.alpha", "einstein.alpha");
        max(Image::SW, "image10.alpha", "image16.alpha");
        max(Image::SE, "image17.alpha", "image21.alpha");
        max(Image::NE, "image23.alpha", "image24.alpha");

        max(Image::NW, "feep.pgm", "image10_small.pgm");
        max(Image::NE, "image26.pgm", "einstein.pgm");
        max(Image::SW, "image10.pgm", "image16.pgm");
        max(Image::SE, "image17.pgm", "image21.pgm");
        max(Image::NW, "image23.pgm", "image24.pgm");

        max(Image::NW, "feep.alpha", "image10_small.pgm");
        max(Image::NE, "image26.alpha", "einstein.pgm");
        max(Image::SW, "image10.alpha", "image16.pgm");
        max(Image::SE, "image17.alpha", "image21.pgm");
        max(Image::SW, "image23.alpha", "image24.pgm");

        max(Image::NW, "feep.pgm", "image10_small.alpha");
        max(Image::NE, "image26.pgm", "einstein.alpha");
        max(Image::SW, "image10.pgm", "image16.alpha");
        max(Image::SE, "image17.pgm", "image21.alpha");
        max(Image::SE, "image23.pgm", "image24.alpha");

    }

};

int main(int argc, char *argv[]) {

    try {
        run_test<CreateSmallAlpha>("CreateSmallAlpha", 10);
        run_test<CreateSmallPGM>("CreateSmallPGM", 10);
        run_test<CreateLargeAlpha>("CreateLargeAlpha", 2);
        run_test<CreateLargePGM>("CreateLargePGM", 1);

        run_test<WriteSmallAlpha>("WriteSmallAlpha", 10);
        run_test<WriteSmallPGM>("WriteSmallPGM", 10);
        run_test<WriteLargeAlpha>("WriteLargeAlpha", 2);
        run_test<WriteLargePGM>("WriteLargePGM", 1);

        run_test<Resize>("Resize", 6);
        run_test<Mirror>("Mirror", 20);

        run_test<Rotate90>("Rotate90", 1);
        run_test<Rotate180>("Rotate180", 6);
        run_test<Rotate270>("Rotate270", 1);

        run_test<ImageMin>("Min", 1);
        run_test<ImageMax>("Max", 1);

    } catch(std::string &s){
        std::cout << s << '\n';
    }
    return 0;
}
