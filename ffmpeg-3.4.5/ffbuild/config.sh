# Automatically generated by configure - do not modify!
shared=no
build_suffix=
prefix=/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64
libdir=${prefix}/lib
incdir=${prefix}/include
rpath=
source_path=.
LIBPREF=lib
LIBSUF=.a

extralibs_avutil="  -lm"
extralibs_avcodec="-L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbisenc -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lm -lshine -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -lmp3lame -lm  -lz -pthread -pthread "
extralibs_avformat="-L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbisenc -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lm -lshine -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -lmp3lame -lm  -lz -pthread -pthread "
extralibs_avdevice="-L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbisenc -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lm -lshine -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -lmp3lame -lm  -lz -pthread -pthread "
extralibs_avfilter="-L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbisenc -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lvorbis -lm -logg -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lm -lshine -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -L/home/hsyuan/lab/ffmpeg-binary-android/build_scripts/x86_64/lib -lopus -lm -lmp3lame -lm  -lz -pthread -pthread "
extralibs_avresample="-lm"
extralibs_postproc=""
extralibs_swscale="-lm"
extralibs_swresample="-lm "
avcodec_deps="avutil"
avdevice_deps="avfilter swscale postproc swresample avformat avcodec avutil"
avfilter_deps="swscale postproc swresample avformat avcodec avutil"
avformat_deps="avcodec avutil"
avresample_deps="avutil"
avutil_deps=""
postproc_deps="avutil"
swresample_deps="avutil"
swscale_deps="avutil"
