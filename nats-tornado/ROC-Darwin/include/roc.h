// Copyright 2016 Rank One Computing Corporation

#ifndef ROC_H
#define ROC_H

#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if defined ROC_LIBRARY || defined BR_LIBRARY
#  if defined _WIN32 || defined __CYGWIN__
#    define ROC_EXPORT __declspec(dllexport)
#  else
#    define ROC_EXPORT __attribute__((visibility("default")))
#  endif
#else
#  if defined _WIN32 || defined __CYGWIN__
#    define ROC_EXPORT __declspec(dllimport)
#  else
#    define ROC_EXPORT
#  endif
#endif

//! [ROC SWIG]
#ifdef SWIG
%module roc
%include cpointer.i
%include carrays.i
%include stdint.i
#ifdef SWIGJAVA
%include enumtypeunsafe.swg
#endif // SWIGJAVA
%{
#include "roc.h"
%}
%pointer_functions(float,   float)
%pointer_functions(uint8_t, uint8_t)
%pointer_functions(size_t,  size_t)
%pointer_functions(roc_gallery,    roc_gallery)
%pointer_functions(roc_host_id,    roc_host_id)
%pointer_functions(roc_similarity, roc_similarity)
%array_functions(char, char_array)
%array_functions(roc_template,   roc_template_array)
%array_functions(roc_similarity, roc_similarity_array)
%array_functions(roc_candidate,  roc_candidate_array)
%array_functions(roc_person_id,  roc_person_id_array)
#endif // SWIG
//! [ROC SWIG]

#define ROC_VERSION_MAJOR 1
#define ROC_VERSION_MINOR 7
#define ROC_VERSION_PATCH 0
#define ROC_VERSION_STRING "1.7.0"

/*!
 * \mainpage
 * \section introduction Introduction
 * Welcome to the ROC SDK documentation!
 * There are five primary ways to use our software:
 *  - \ref api          - \copybrief api
 *  - \ref api_wrappers - \copybrief api_wrappers
 *  - \ref cli          - \copybrief cli
 *  - \ref gui          - \copybrief gui
 *  - \ref web          - \copybrief web
 *
 * \section important_words Important Words
 * | Word                                 | Definition                       |
 * |--------------------------------------|----------------------------------|
 * | \ref roc_represent "represent"       | \copybrief roc_represent         |
 * | \ref roc_template "template"         | \copybrief roc_template          |
 * | \ref roc_compare_templates "compare" | \copybrief roc_compare_templates |
 * | \ref roc_similarity "similarity"     | \copybrief roc_similarity        |
 * | \ref roc_gallery "gallery"           | \copybrief roc_gallery           |
 *
 * \page api_wrappers API Wrappers
 * \brief \em Experimental Java, C# and Python interfaces that wrap our C API.
 *
 * \section api_wrappers_overview Overview
 * The ROC SDK ships with API wrappers for the \c Java, \c C# and \c Python
 * programming languages.
 * The wrappers live in the \c java, \c csharp and \c python subdirectories of
 * the SDK respectively.
 * In addition to the language-specific interface files, each folder also
 * contains an \c examples subfolder with translations of
 * \c examples/roc_example_verify.c and \c examples/roc_example_search.c.
 * Lastly, source code for the API translation is provided in the \c roc_swig.c
 * file as a reference for resolving specific technical questions.
 *
 * At this time, the \ref video_decoding portion of the C API is \em not
 * supported in the wrappers.
 *
 * \section api_wrappers_reproducibility Reproducibility
 * The wrappers are generated automatically using [SWIG](http://www.swig.org/),
 * thus it is trivial to reproduce them or generate new wrappers for other
 * programming languages.
 * The general syntax is:
 * \code
 * $ cd include
 * $ swig -<language> -module roc roc.h
 * \endcode
 *
 * \section api_wrappers_help Help
 * To the extent possible, symbol names are identical between the wrappers and
 * the C API, thus the \ref api documentation should continue to serve as the
 * primary reference.
 * A reading of [SWIG Basics](http://www.swig.org/Doc3.0/SWIG.html) and the
 * language specific documentation for
 * [Java](http://www.swig.org/Doc3.0/Java.html),
 * [C#](http://www.swig.org/Doc3.0/CSharp.html) and
 * [Python](http://www.swig.org/Doc3.0/Python.html) is encouraged.
 *
 * The most difficult component of these wrappers is understanding how SWIG
 * handles pointers and arrays.
 * Cross-referencing the following documents will offer clarity:
 * - The SWIG documentation for
 *   <a href="http://www.swig.org/Doc3.0/Library.html#Library_nn4">
 *   <tt>\%pointer_functions</tt></a> and
 *   <a href="http://www.swig.org/Doc3.0/Library.html#Library_carrays">
 *   <tt>\%array_functions</tt></a>.
 * - The use of \c \%pointer_functions and \c \%array_functions in \ref roc.h,
 *   also reproduced \ref roc_swig "here".
 * - The provided \c verify and \c search examples that make use of these
 *   functions.
 *
 * If in doubt, please direct questions to \c support@rankone.io.
 *
 * \section api_wrappers_examples Examples
 * \subsection api_wrappers_examples_java Java
 * \code
 * $ cd java
 * $ javac *.java examples/roc_example_*.java
 * $ java roc_example_verify ../data/josh_1.jpg ../data/josh_2.jpg
 * $ java roc_example_search ../data/roc.jpg ../data/josh_2.jpg
 * \endcode
 *
 * \subsection api_wrappers_examples_csharp C#
 * Using the [Mono](http://www.mono-project.com/) compiler.
 * \code
 * $ cd csharp
 * $ mcs -platform:x64 *.cs examples/roc_example_verify.cs -out:roc_example_verify.exe
 * $ mcs -platform:x64 *.cs examples/roc_example_search.cs -out:roc_example_search.exe
 * $ mono roc_example_verify.exe ../data/josh_1.jpg ../data/josh_2.jpg
 * $ mono roc_example_search.exe ../data/roc.jpg ../data/josh_2.jpg
 * \endcode
 * When calling \c mono on OS X include the <tt>\-\-arch=64</tt> flag.
 *
 * \subsection api_wrappers_examples_python Python
 * On Windows be sure to use a 64-bit installation of Python.
 * \code
 * $ cd python
 * $ python examples/roc_example_verify.py ../data/josh_1.jpg ../data/josh_2.jpg
 * $ python examples/roc_example_search.py ../data/roc.jpg ../data/josh_2.jpg
 * \endcode
 *
 * \page cli Command Line Interface
 * \brief A robust Command Line Interface (CLI) wrapping key ROC SDK API
 *        functions.
 *        The CLI is ideal for headless server environments or scripts that
 *        perform face recognition tasks.
 *
 * \section cli_workflow Workflow
 * Below is a diagram illustrating the common workflow through our ten command
 * line applications.
 * As you'll soon see, each application is very simple, doing one thing only and
 * (we hope) one thing well.
 * Click on an application to pull up its documentation and example usage.
 *
 * \htmlinclude cli.svg
 *
 * \section cli_applications Applications
 * Here's a list of the applications along with a brief description of each.
 * | Application                  | Description                    |
 * |------------------------------|--------------------------------|
 * | \subpage roc-at              | \copybrief roc-at              |
 * | \subpage roc-cluster         | \copybrief roc-cluster         |
 * | \subpage roc-consolidate     | \copybrief roc-consolidate     |
 * | \subpage roc-metadata        | \copybrief roc-metadata        |
 * | \subpage roc-remove          | \copybrief roc-remove          |
 * | \subpage roc-represent       | \copybrief roc-represent       |
 * | \subpage roc-represent-video | \copybrief roc-represent-video |
 * | \subpage roc-search          | \copybrief roc-search          |
 * | \subpage roc-track           | \copybrief roc-track           |
 * | \subpage roc-validate        | \copybrief roc-validate        |
 * | \subpage roc-compare         | \copybrief roc-compare         |
 *
 * \section cli_gallery_files Gallery Files
 * \copybrief roc_gallery_file
 * This file format is shared amongst all command line applications and is
 * identified by convention using a <tt>.t</tt> suffix.
 *
 * \subsection cli_gallery_file_concatenation Concatenation
 * An important aspect of gallery files is that two or more of them can be
 * concatenated together to produce one larger gallery file.
 * For example:
 * \verbatim $ cat a.t b.t > ab.t \endverbatim
 *
 * \subsection cli_gallery_file_interoperability Interoperability
 * Gallery files produced from the \ref cli are interoperable with those
 * produced from the \ref api.
 * See \ref roc_gallery_file for details.
 *
 * \page api Application Programming Interface
 * \brief All ROC SDK capabilities are accessible via a C-language Application
 *        Programming Interface (API).
 *        This approach is well suited for software engineers looking to build
 *        custom applications using ROC SDK face recognition functions.
 *
 * \section getting_started Getting Started
 * Add <tt>/path/to/ROC_SDK/include</tt> to your include directories and
 * <tt>/path/to/ROC_SDK/lib</tt> to your lib directories.
 * <tt>\#include \<roc.h\></tt> and link against <tt>roc</tt>.
 * Additionally link against <tt>roc_video</tt> for \ref video_decoding.
 *
 * \section examples Examples
 * Source code for these examples is available in the \c examples folder.
 * - \ref roc_example_verify "1-to-1 Verification"
 * - \ref roc_example_search "1-to-N Search"
 *
 * \section api_overview Overview
 * \ref error_handling <br>
 * \copydetails error_handling
 *
 * \ref initialization <br>
 * \copydetails initialization
 *
 * \ref media_decoding <br>
 * \copydetails image_decoding
 * \copydetails video_decoding
 * \copydetails media_decoding
 *
 * \ref template_generation <br>
 * \copydetails template_generation
 *
 * \ref template_io <br>
 * \copydetails template_io
 *
 * \ref gallery_construction <br>
 * \copydetails gallery_construction
 *
 * \ref comparison <br>
 * \copydetails comparison
 *
 * \ref search <br>
 * \copydetails search
 *
 * \ref identity_discovery <br>
 * \copydetails identity_discovery
 *
 * \section thread_safety Thread Safety
 * All functions are marked one of:
 * - \anchor thread-safe \b thread-safe
 *   Can be called simultaneously from multiple threads, even when the
 *   invocations use the same data.
 * - \anchor reentrant \b reentrant
 *   Can be called simultaneously from multiple threads, but only if each
 *   invocation uses different data.
 * - \anchor thread-unsafe \b thread-unsafe
 *   Can not be called simultaneously from multiple threads.
 *
 * \section api_workflow Workflow
 * \htmlinclude api.svg
 *
 * \page roc_example_verify roc_example_verify.c
 * \brief Source code for <tt>examples/roc_example_verify.c</tt>.
 *
 * \snippet roc_example_verify.c ROC Example Verify Application
 *
 * \page roc_example_search roc_example_search.c
 * \brief Source code for <tt>examples/roc_example_search.c</tt>.
 *
 * \snippet roc_example_search.c ROC Example Search Application
 *
 * \page roc_swig ROC SWIG
 * \brief SWIG module definitions.
 *
 * \snippet roc.h ROC SWIG
 */

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \defgroup error_handling Error Handling
 * \brief Handling errors.
 *
 * All ROC functions return a printable \ref roc_error message by design.
 * The \ref ROC_ATTEMPT macro and \ref roc_ensure function are provided as basic
 * error handling methods.
 *
 * @{
 */

/*!
 * \brief A printable error string.
 *
 * All functions in the ROC API return a \ref roc_error.
 * A value of \c NULL indicates \em success, and all other values indicate
 * \em failure.
 * \note Failure values are statically-allocated strings that should \em not be
 * freed.
 *
 * \par Example
 * \code{C}
 * roc_error error = ...;
 * if (error) {
 *   puts(error);
 *   abort();
 * }
 * \endcode
 *
 * \see \ref ROC_ATTEMPT \ref roc_ensure
 */
typedef const char *roc_error;

/*!
 * \brief A simple return-error-message error handling macro.
 * \par Example
 * \code{C}
 * ROC_ATTEMPT(roc_initialize(NULL))
 * \endcode
 * \see \ref roc_ensure
 */
#define ROC_ATTEMPT(EXPRESSION)           \
{                                         \
    const roc_error error = (EXPRESSION); \
    if (error)                            \
        return error;                     \
}

/*!
 * \brief A simple print-and-abort error handling function.
 *
 * \code
 * roc_error roc_ensure(roc_error error)
 * {
 *     if (error) {
 *         fprintf(stderr, "ROC Error: %s\n", error);
 *         abort();
 *     }
 * }
 * \endcode
 *
 * \param[in] error Error return value from a ROC API function call.
 * \remark This function is \ref thread-safe.
 * \see \ref ROC_ATTEMPT
 */
ROC_EXPORT void roc_ensure(roc_error error);

/** @} */ // end of error_handling

/*!
 * \defgroup initialization Initialization
 * \brief Initializing the SDK.
 *
 * A ROC application begins with a call to \ref roc_initialize, and ends with
 * a call to \ref roc_finalize.
 * For license management see \ref roc_get_host_id and \ref roc_free_host_id.
 *
 * @{
 */

/*!
 * \brief Call once at the start of the application before making any other
 *        calls to the API.
 *
 * The \p sdk_path is the path to the root of the ROC SDK.
 * The root SDK directory should contain the <tt>ROC.lic</tt> license file,
 * see \ref roc_host_id for details.
 * It is permissible for the SDK directory to be \em read-only.
 *
 * \section automatic_localization Automatic Localization
 * If \p sdk_path is \c NULL, ROC will attempt to locate the SDK automatically
 * relative to:
 *
 *  1. The application's working directory.
 *  2. Entries in the \c PATH environment variable.
 *
 * Automatic SDK localization will succeed if any of these paths is the SDK
 * path, or a subdirectory thereof.
 *
 * \par Example
 * \code{C}
 * const char *sdk_path = ...;
 * roc_initialize(sdk_path);
 * \endcode
 *
 * \param[in] sdk_path Path to the root of the ROC SDK, or \c NULL for
 *                     \ref automatic_localization.
 * \remark This function is \ref thread-unsafe and must only be called once.
 * \see \ref roc_finalize
 */
ROC_EXPORT roc_error roc_initialize(const char *sdk_path);

/*!
 * \brief Call once at the end of the application after making all other calls
 *        to the API.
 *
 * This will free memory allocated during initialization.
 * Calling \ref roc_initialize after this function to re-initialize the SDK is
 * \em not supported.
 * \remark This function is \ref thread-unsafe and must only be called once.
 *
 * \par Example
 * \code{C}
 * roc_finalize();
 * \endcode
 * \see \ref roc_initialize
 */
ROC_EXPORT roc_error roc_finalize();

/*!
 * \brief The host ID uniquely identifies a specific machine and is used for
 *        license enforcement.
 *
 * A null-terminated JSON string.
 * Retrieve the host ID for the current machine with \ref roc_get_host_id,
 * free a host ID after use with \ref roc_free_host_id.
 */
typedef const char *roc_host_id;

/*!
 * \brief Retrieve the \ref roc_host_id of the current machine.
 *
 * This function provides output identical to running the \c zlmhostid
 * application included in the \c bin folder of the SDK.
 * The output of this function (or the \c zlmhostid application) should be
 * emailed to \c support@rankone.io to obtain a valid license file prior to
 * calling \ref roc_initialize.
 * Rank One uses the \ref roc_host_id to generate the <tt>ROC.lic</tt> license
 * file that should be copied to the ROC SDK root directory, overwriting the
 * placeholder license file of the same name.
 *
 * Free the returned \ref roc_host_id after use with \ref roc_free_host_id.
 *
 * This function can be called before \ref roc_initialize.
 * \par Example
 * \code{C}
 * roc_host_id host_id;
 * roc_get_host_id(&host_id);
 * \endcode
 * \param[out] host_id The \ref roc_host_id for the current machine.
 * \remark This function is \ref thread-unsafe.
 */
ROC_EXPORT roc_error roc_get_host_id(roc_host_id *host_id);

/*!
 * \brief Free a \ref roc_host_id previously returned by \ref roc_get_host_id.
 *
 * This function can be called before \ref roc_initialize.
 * \par Example
 * \code{C}
 * roc_host_id host_id = ...;
 * roc_free_host_id(host_id);
 * \endcode
 * \param[in] host_id \ref roc_host_id to free.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_free_host_id(roc_host_id host_id);

/** @} */ // end of initialization

/*!
 * \defgroup media_decoding Media Decoding
 * \brief Reading images and videos.
 *
 * Free an image with \ref roc_free_image.
 *
 * @{
 */

/*!
 * \brief Supported image formats.
 */
typedef enum roc_color_space
{
    ROC_GRAY8, /*!< \brief 1-channel grayscale, 8-bit depth. */
    ROC_BGR24  /*!< \brief 3-channel color (BGR order), 8-bit depth. */
} roc_color_space;

/*!
 * \brief Common representation for still images and video frames.
 *
 * Images can be read with \ref roc_read_image or \ref roc_read_frame, and freed
 * with \ref roc_free_image.
 *
 * Pixels are stored in _row-major_ order.
 * In other words, pixel layout with respect to decreasing memory spatial
 * locality is \a channel, \a column, \a row.
 * Thus pixel intensity can be retrieved as follows:
 *
 * \code{C}
 * uint8_t get_intensity(roc_image image,
 *                       size_t channel,
 *                       size_t column,
 *                       size_t row)
 * {
 *     const size_t channels = (image.color_space == ROC_BGR24 ? 3 : 1);
 *     const size_t index = row*image.step + column*channels + channel;
 *     return image.data[index];
 * }
 * \endcode
 *
 * Coordinate (0, 0) corresponds to the top-left corner of the image.
 * Coordinate (width-1, height-1) corresponds to the bottom-right corner of the
 * image.
 *
 */
typedef struct roc_image
{
    uint8_t *data; /*!< \brief Buffer of pixel intensities. */
    size_t width;  /*!< \brief Column count in pixels. */
    size_t height; /*!< \brief Row count in pixels. */
    size_t step;   /*!< \brief Bytes per row, including padding. */
    roc_color_space color_space; /*!< \brief Interpretation of #data. */
} roc_image;

/*!
 * \brief Frees the memory previously allocated for a \ref roc_image.
 * \param[in] image Image to free.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_free_image(roc_image image);

/*!
 * \defgroup image_decoding Image Decoding
 * \brief Reading images.
 *
 * Decode a \ref roc_image from a file with \ref roc_read_image or from a
 * buffer with \ref roc_decode_image.
 *
 * @{
 */

/*!
 * \brief Read an image from a file.
 *
 * Free \p image after use with \ref roc_free_image.
 *
 * \section supported_image_formats Supported Image Formats
 * - Windows bitmaps - *.bmp, *.dib
 * - JPEG files - *.jpeg, *.jpg, *.jpe
 * - JPEG 2000 files - *.jp2
 * - Portable Network Graphics - *.png
 * - Portable image format - *.pbm, *.pgm, *.ppm
 * - Sun rasters - *.sr, *.ras
 * - TIFF files - *.tiff, *.tif
 *
 * \section color_space_considerations Color Space Considerations
 * \ref roc_represent operates natively on \ref ROC_GRAY8 images, and will
 * automatically convert provided \ref ROC_BGR24 images.
 * When you don't otherwise need color images, as a speed/memory optimization
 * you may read an image file directly into grayscale to eliminate the color
 * space conversion in \ref roc_represent.
 *
 * \par Example
 * \code{C}
 * roc_image image;
 * roc_read_image("lenna.jpeg", ROC_GRAY8, &image);
 * \endcode
 *
 * \param[in] file_name Path to the image file.
 * \param[in] color_space Desired color space, see
 *                        \ref color_space_considerations.
 * \param[out] image Address to store the decoded image.
 * \remark This function is \ref reentrant.
 * \see roc_decode_image
 */
ROC_EXPORT roc_error roc_read_image(const char *file_name,
                                    roc_color_space color_space,
                                    roc_image *image);

/*!
 * \brief Decode an image from a buffer.
 *
 * Free \p image after use with \ref roc_free_image.
 *
 * See \ref roc_read_image for \ref supported_image_formats and
 * \ref color_space_considerations.
 *
 * \par Example
 * \code{C}
 * size_t len = ...;
 * const char *data = ...;
 * roc_image image;
 * roc_decode_image(len, data, ROC_GRAY8, &image);
 * \endcode
 *
 * \param[in] len Length of \p data.
 * \param[in] data Encoded image buffer.
 * \param[in] color_space Desired color space, see
 *                        \ref color_space_considerations.
 * \param[out] image Address to store the decoded image.
 * \remark This function is \ref reentrant.
 * \see roc_read_image
 */
ROC_EXPORT roc_error roc_decode_image(size_t len,
                                      const uint8_t *data,
                                      roc_color_space color_space,
                                      roc_image *image);

/** @} */ // end of image_decoding

/*!
 * \defgroup video_decoding Video Decoding
 * \brief Reading videos.
 *
 * Open a \ref roc_video with \ref roc_open_video, read frames sequentially with
 * \ref roc_read_frame or \ref roc_read_keyframe, seek to a timestamp with
 * \ref roc_seek and close a video with \ref roc_close_video.
 *
 * @{
 */

#ifndef SWIG

/*!
 * \brief Handle to a private video decoding type.
 */
typedef struct roc_video_type *roc_video;

/*!
 * \brief Time in milliseconds
 */
typedef uint32_t roc_time;

/*!
 * \brief Video metadata
 */
typedef struct roc_video_metadata
{
    size_t width;      /*!< \brief Width of the video's picture. */
    size_t height;     /*!< \brief Height of the video's picture. */
    roc_time duration; /*!< \brief Length of the opened video in milliseconds.
                                   Defaults to 0 for videos of unkown duration
                                   such as webcam and IP camera video
                                   streams. */
    int bit_rate; /*!< \brief Number of bits per unit of time. Equal to
                              \code{C} (video_bytes*8) / duration \endcode */
} roc_video_metadata;

/*!
 * \brief Open a video for reading.
 *
 * In addition to files on disk, this function supports capture devices such
 * as a webcam by specifying the device index as the file name, as well as
 * streaming videos over network protocols including http/https.
 *
 * Read frames sequentially with \ref roc_read_frame or \ref roc_read_keyframe.
 * Seek to a timestamp with \ref roc_seek.
 * Close a video after use with \ref roc_close_video.
 *
 * \section supported_video_formats Supported Video Formats
 * ROC SDK makes use of the system's FFmpeg / libAV library so supported file
 * formats may vary slightly by installation.
 * The standard list of supported formats is available
 * [here](http://www.ffmpeg.org/general.html#Video-Codecs).
 *
 * \par Example
 * \code{C}
 * roc_video video;
 * roc_video_metadata video_metadata;
 * roc_open_video("gangnam-style.mp4", &video, &video_metadata);
 *
 * roc_video webcam;
 * roc_open_video("0", &webcam, NULL);
 *
 * roc_video ip_camera;
 * roc_open_video("http://204.248.124.202/mjpg/video.mjpg", &ip_camera, NULL);
 *
 * roc_video http_video
 * roc_open_video("http://www.sample-videos.com/video/mp4/480/big_buck_bunny_480p_1mb.mp4",
 *                &http_video, NULL);
 * \endcode
 *
 * \param[in] file_name Path to video file.
 * \param[in] color_space Desired color space, see
 *                        \ref color_space_considerations.
 * \param[out] video Address to store the opened video.
 * \param[out] metadata Address to metadata associated with the opened video,
 *                      or \c NULL.
 * \remark This function is \ref reentrant.
 * \see \ref roc_close_video
 */
ROC_EXPORT roc_error roc_open_video(const char *file_name,
                                    roc_color_space color_space,
                                    roc_video *video,
                                    roc_video_metadata *metadata);

/*!
 * \brief Seek to a \ref roc_time timestamp of an opened video.
 *
 * Seeks to the nearest keyframe of the given timestamp.  If \p timestamp
 * is beyond the duration of the video, the function will seek to the
 * end of the video and return without error.
 *
 * \par Example
 * \code{C}
 * roc_video video = ...;
 * roc_time timestamp = ...;
 * roc_seek(video, timestamp);
 * \endcode
 *
 * \param[in] video Video to perform seek on.
 * \param[in] timestamp Timestamp to seek to.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_seek(roc_video video,
                              roc_time timestamp);

/*!
 * \brief Read the current frame and advance the video to the next frame.
 *
 * If no frames are left in \p video, \p frame.data will be set to \c NULL
 * and the function will return without error.
 *
 * Free \p frame after use with \ref roc_free_image.
 *
 * \par Example
 * \code{C}
 * roc_video video = ...;
 * roc_image frame;
 * roc_time timestamp;
 * roc_read_frame(video, &frame, &timestamp);
 * \endcode
 *
 * \param[in] video Video to decode.
 * \param[out] frame Address to store the decoded frame.
 * \param[out] timestamp Address to store the current position of the video
 *                       file in milliseconds or video capture timestamp,
 *                       or \c NULL if this value is not needed.
 * \remark This function is \ref reentrant.
 * \see \ref roc_read_keyframe
 */
ROC_EXPORT roc_error roc_read_frame(roc_video video,
                                    roc_image *frame,
                                    roc_time *timestamp);

/*!
 * \brief Read the next key frame and advance the video to the next frame.
 *
 * If no key frames are left in \p video, \p frame.data will be set to \c NULL
 * and the function will return without error.
 *
 * Free \p frame after use with \ref roc_free_image.
 *
 * \par Example
 * \code{C}
 * roc_video video = ...;
 * roc_image frame;
 * roc_time timestamp;
 * roc_read_keyframe(video, &frame, &timestamp);
 * \endcode
 *
 * \param[in] video Video to decode.
 * \param[out] frame Address to store the decoded key frame.
 * \param[out] timestamp Address to store the current position of the video
 *                       file in milliseconds or video capture timestamp,
 *                       or \c NULL if this value is not needed.
 * \remark This function is \ref reentrant.
 * \see \ref roc_read_keyframe
 */
ROC_EXPORT roc_error roc_read_keyframe(roc_video video,
                                       roc_image *frame,
                                       roc_time *timestamp);

/*!
 * \brief Close an open video.
 *
 * This will free memory associated with \p video.
 *
 * \par Example
 * \code{C}
 * roc_video video = ...;
 * roc_close_video(video);
 * \endcode
 *
 * \param[in] video The video to close.
 * \remark This function is \ref reentrant.
 * \see \ref roc_open_video
 */
ROC_EXPORT roc_error roc_close_video(roc_video video);

#endif // !SWIG

/** @} */ // end of video_decoding
/** @} */ // end of media_decoding

/*!
 * \defgroup template_generation Template Generation
 * \brief Process faces in an image.
 *
 * Process faces in an image with \ref roc_represent.
 * Free a face \ref roc_template after use with \ref roc_free_template.
 *
 * @{
 */

/*!
 * \brief Set the parameters used by \ref ROC_THUMBNAIL in \ref roc_represent.
 *
 * A \em thumbnail is an aligned and cropped face image suitable for displaying.
 *
 * \par Example
 * \code{C}
 * roc_set_thumbnail_parameters(192, 256, 0.6, 32);
 * \endcode
 *
 * \param[in] width Thumbnail image width in pixels.
 *                  The default is \b 192, and the range is 32 to 1024.
 * \param[in] height Thumbnail image height in pixels.
 *                   The default is \b 256, and the range is 32 to 1024.
 * \param[in] scale Thumbnail face scale, where larger values are a tighter
 *                  cropping.
 *                  The default is \b 0.6, and the range is 0.1 to 1.0.
 * \param[in] quality Thumbnail quality, where larger values are higher quality
 *                    at the expense of more storage.
 *                    The default is \b 32, and the range is 0 to 100.
 * \remark This function is \ref thread-unsafe.
 */
ROC_EXPORT roc_error roc_set_thumbnail_parameters(int width,
                                                  int height,
                                                  float scale,
                                                  float quality);

/*!
 * \brief Supported algorithm configurations.
 * \see \ref specifying_an_algorithm_id
 */
enum roc_algorithm_options
{
    ROC_FRONTAL = 0x0000, /*!< \brief Detect faces from -30 to +30 degrees yaw.
                                      */
    ROC_FULL    = 0x0001, /*!< \brief Detect faces from -100 to +100 degrees
                                      yaw. */
    ROC_PARTIAL = 0x0002, /*!< \brief Detect faces in which the upper or lower
                                      half of the face is occluded. */
    ROC_MANUAL  = 0x0004, /*!< \brief Bypass automatic face detection by using
                                      caller-provided bounding boxes.

                               \par Required Fields
                               Templates passed to \ref roc_represent are
                               assumed to provide valid values for:
                                 - \ref roc_template::x
                                 - \ref roc_template::y
                                 - \ref roc_template::width
                                 - \ref roc_template::height
                                 - \ref roc_template::confidence
                                 - \ref roc_template::md_size
                                 - \ref roc_template::md

                               All other fields may be uninitialized.

                               \par When To Use
                               The suggested use case for \ref ROC_MANUAL is
                               when the caller wishes to break up face
                               detection (e.g. \ref ROC_FRONTAL) and face
                               representation (e.g. \ref ROC_FR) into two
                               separate calls to \ref roc_represent.
                               The required fields must be obtained from a prior
                               call to \ref roc_represent, faces obtained from
                               alternative face detection algorithms or manual
                               annotation are not supported.

                               \par Memory Management
                               Importantly, the caller is responsible for
                               managing the memory of both the input \em and
                               output templates.
                               The input and output templates are always
                               distinct.
                               */

    ROC_FR = 0x0010, /*!< \brief Represent in-the-wild faces for comparison. */
    ROC_ID = 0x0020, /*!< \brief Represent controlled-capture faces for
                                 comparison.

                          Use this algorithm for improved accuracy on databases
                          of driver's license, passport, mugshot or other
                          ID-card like images. */

    ROC_PITCHYAW  = 0x0100, /*!< \brief Add \c Yaw and \c Pitch (degrees)
                                        estimation to the template metadata. */
    ROC_GENDER    = 0x0200, /*!< \brief Add \c Gender (\c Male or \c Female)
                                        estimation to the template metadata.
                                        Requires \ref ROC_FR. */
    ROC_AGE       = 0x0400, /*!< \brief Add \c Age (years old) estimation to
                                        the template metadata. Requires
                                        \ref ROC_FR. */
    ROC_OCCLUSION = 0x0800, /*!< \brief Add \c Occlusion estimation to the
                                        template metadata, value is either
                                        \c true or \c false. Requires
                                        \ref ROC_FR. */
    ROC_LIPS      = 0x1000, /*!< \brief Add \c Lips position estimation to the
                                        template metadata, value is either
                                        \c "Together" or \c "Apart". */

    ROC_THUMBNAIL = 0x8000, /*!< \brief Align, scale, crop, \c JPEG encode, and
                                        store the face image in
                                        \ref roc_template::tn.

                                 Control thumbnail quality with
                                 \ref roc_set_thumbnail_parameters. */

    ROC_INVALID = 0x010000, /*!< \brief The \ref roc_template was not
                                        initialized by \ref roc_represent. */

    /*!
     * \brief The format of \ref roc_template::fv changes between releases,
     *        this field is used to check template compatibility.
     *
     * \code
     * roc_template t = ...;
     * if (t->algorithm_id & ROC_TEMPLATE_VERSION_MASK == ROC_TEMPLATE_VERSION)
     *     ...; // compatible with current SDK
     * \endcode
     */
    ROC_TEMPLATE_VERSION = (ROC_VERSION_MAJOR << 28)
                         + (ROC_VERSION_MINOR << 24),

    /*! \brief See \ref ROC_TEMPLATE_VERSION. */
    ROC_TEMPLATE_VERSION_MASK = 0x7F000000,
};

/*!
 * \brief A combination of \ref roc_algorithm_options.
 * \see \ref specifying_an_algorithm_id
 */
typedef uint32_t roc_algorithm_id;

/*!
 * \brief Pre-load the model files to be used by \ref roc_represent.
 *
 * See \ref lazy_initialization for details.
 *
 * \par Example
 * \code{C}
 * roc_preload(ROC_FRONTAL | ROC_FR);
 * \endcode
 *
 * \param[in] algorithm_id Pre-load the model files to be used by
 *                         \ref roc_represent for this \ref roc_algorithm_id.
 * \remark This function is \ref thread-safe.
 */
ROC_EXPORT roc_error roc_preload(roc_algorithm_id algorithm_id);

/*!
 * \brief Estimate the face bounding box from landmarks.
 *
 * Used for manual face enrollment with \ref ROC_MANUAL.
 *
 * \par Example
 * \code{C}
 * float left_eye_x = ...;
 * float left_eye_y = ...;
 * float right_eye_x = ...;
 * float right_eye_y = ...;
 * float chin_x = ...;
 * float chin_y = ...;
 * float face_x, face_y, face_width, face_height;
 * roc_landmarks_to_face(left_eye_x, left_eye_y,
 *                       right_eye_x, right_eye_y,
 *                       chin_x, chin_y,
 *                       &face_x, &face_y, &face_width, &face_height);
 * \endcode
 * \param[in] left_eye_x Left eye horizontal location (pixels).
 * \param[in] left_eye_y Left eye vertical location (pixels).
 * \param[in] right_eye_x Right eye horizontal location (pixels).
 * \param[in] right_eye_y Right eye vertical location (pixels).
 * \param[in] chin_x Chin horizontal location (pixels).
 * \param[in] chin_y Chin vertical location (pixels).
 * \param[out] face_x Face horizontal offset (pixels).
 * \param[out] face_y Face vertical offset (pixels).
 * \param[out] face_width Face horizontal size (pixels).
 * \param[out] face_height Face vertical size (pixels).
 */
ROC_EXPORT roc_error roc_landmarks_to_face(float left_eye_x,
                                           float left_eye_y,
                                           float right_eye_x,
                                           float right_eye_y,
                                           float chin_x,
                                           float chin_y,
                                           float *face_x,
                                           float *face_y,
                                           float *face_width,
                                           float *face_height);

/*!
 * \brief Default value for \ref roc_template::timestamp, indicating the
 *        template was generated from a still image.
 *
 * Equal to 2^32 - 1.
 */
#define ROC_NO_TIMESTAMP 0xFFFFFFFF

/*!
 * \brief A unique identifier used to associate multiple \ref roc_template.
 * \see \ref identity_discovery
 */
typedef uint32_t roc_person_id;

/*!
 * \brief Default value for \ref roc_template::person_id, indicating the
 *        template has no known associations.
 *
 * Equal to 2^32 - 1.
 */
#define ROC_UNKNOWN_PERSON 0xFFFFFFFF

/*!
 * \brief A digital encoding of a face.
 *
 * A pair of templates can be compared for similarity.
 *
 * Templates are designed with the following considerations in mind:
 * - Maximizing the retention of the unique identifying characteristics of a
 *   face.
 * - Minimizing the computation time needed to compare two templates.
 * - Minimizing the computation time needed to generate a template.
 * - Minimizing the storage space required to save a template.
 *
 * \section template_metadata Metadata
 * A template's <i>metadata</i> is a <a href="http://json.org/"><i>Java Script
 * Object Notation</i> (JSON)</a> string containing at least the following keys:
 * | Key          | Definition                                         |
 * |--------------|----------------------------------------------------|
 * | \c LeftEyeX  | Left eye horizontal location (pixels).             |
 * | \c LeftEyeY  | Left eye vertical location (pixels).               |
 * | \c RightEyeX | Right eye horizontal location (pixels).            |
 * | \c RightEyeY | Right eye vertical location (pixels).              |
 * | \c ChinX     | Chin horizontal location (pixels).                 |
 * | \c ChinY     | Chin vertical location (pixels).                   |
 * | \c Pose      | Pose estimation (Frontal, RightAngled, LeftAngled) |
 *
 * Additional keys exist for the requested \ref metadata_options.
 * Metadata may be queried and edited using \ref roc_get_metadata and
 * \ref roc_set_metadata.
 *
 * \section feature_vector Feature Vector
 * A template's <i>feature vector</i> is the statistical model of the
 * distinguishing characteristics of a face and is the basis for measuring
 * \ref roc_similarity.
 * It is stored in the template as \ref roc_template::fv and has length
 * \ref roc_template::fv_size.
 *
 * \section face_quality Face Quality
 * A <i>face quality</i> metric is a predictor of how accurately a template
 * will perform in recognition.
 * A higher face quality indicates a lower false non-match rate.
 * The use of a face quality metric most often arises when one has multiple
 * templates of a person and needs to decide which to add to a gallery.
 * Absent of adding all the templates (or some subset thereof using
 * \ref roc_consolidate), we recommend using \ref roc_template::confidence
 * as the face quality metric, keeping the template with the highest face
 * detection confidence.
 *
 * \section face_liveness_detection Face Liveness Detection
 * A <i>face liveness detection</i> algorithm attempts to determine if the
 * detected face is a living person or an impostor trying to defeat the system
 * with a stolen face image.
 *
 * A <i>dynamic</i> algorithm generally involves asking the user to complete a
 * task.
 * For example, asking the user to turn their head to the left or the right,
 * cover their mouth with their hand, or open their mouth.
 * These movements can be measured using \ref ROC_PITCHYAW, \ref ROC_OCCLUSION,
 * and \ref ROC_LIPS respectively.
 * These algorithms generally have low error rates, at the cost of requiring a
 * few seconds of interaction from the user.
 *
 * A <i>static</i> algorithm attempts to detect the impostor from a single
 * image.
 * For example, detecting if the face image is on a printed piece of paper or
 * computer screen.
 * These algorithms generaly have higher error rates, with the benefit that they
 * do not require interaction from the user.
 * At the present time, the ROC SDK does not support this type of liveness
 * detection.
 */
typedef struct roc_template
{
    roc_algorithm_id algorithm_id; /*!< \brief The value of
                                               \ref roc_algorithm_id passed to
                                               \ref roc_represent to construct
                                               this template. */
    roc_time timestamp; /*!< \brief Face video timestamp or
                                    \ref ROC_NO_TIMESTAMP by default. */
    int32_t x; /*!< \brief Face horizontal offset (pixels). */
    int32_t y; /*!< \brief Face vertical offset (pixels). */
    uint32_t width;  /*!< \brief Face horizontal size (pixels). */
    uint32_t height; /*!< \brief Face vertical size (pixels). */
    float confidence; /*!< \brief Face detection confidence. */
    roc_person_id person_id; /*!< \brief Unique identifier for the person or
                                         \ref ROC_UNKNOWN_PERSON by default. */
    uint32_t md_size; /*!< \brief Length of a null-terminated JSON \ref md
                                  string, including the null-terminator
                                  character. */
    uint32_t fv_size; /*!< \brief Length of the feature vector \ref fv. */
    uint32_t tn_size; /*!< \brief Length of face thumbnail \ref tn. */
    const char *md; /*!< \brief Null-terminated JSON string of length
                                \ref md_size. */
    const uint8_t *fv; /*!< \brief \ref feature_vector of length
                                   \ref fv_size. */
    const uint8_t *tn; /*!< \brief JPEG-encoded face thumbnail of length
                                   \ref tn_size, see \ref ROC_THUMBNAIL. */
} roc_template;

/*!
 * \brief Detect faces in an image and process them into templates for
 *        comparison.
 *
 * Each face is represented by a #roc_template.
 * In the case that the number of enrollable faces is greater than \p k, the
 * implementation will choose which faces to exclude,
 * potentially returning early before scanning the entire image.
 * In the case that the number of enrollable faces is less than \p k, the
 * trailing elements of \p templates will have \ref roc_template::algorithm_id
 * set to \ref ROC_INVALID.
 * The populated \p templates will be returned sorted by decreasing
 * \ref roc_template::confidence.
 *
 * Each \ref roc_template in \p templates should be freed after use with
 * \ref roc_free_template.
 *
 * This function is exposed in the \ref cli as \ref roc-represent and
 * \ref roc-represent-video.
 *
 * \section specifying_an_algorithm_id Specifying an Algorithm ID
 * The \p algorithm_id is a combination of \ref roc_algorithm_options indicating
 * how to process faces in an image.
 * There are three components to an algorithm id: detection, representation and
 * metadata.
 * Components are combined together using an \em or operation, as in
 * \ref algorithm_id_examples.
 * You do not need to specify \ref ROC_TEMPLATE_VERSION, this will be added
 * automatically.
 *
 * \subsection detection_options Detection Options
 * <i>Exactly one</i> option should be specified to indicate the desired face
 * detection mechanism.
 *
 * | Detection Options | Description            |
 * |-------------------|------------------------|
 * | \ref ROC_FRONTAL  | \copybrief ROC_FRONTAL |
 * | \ref ROC_FULL     | \copybrief ROC_FULL    |
 * | \ref ROC_PARTIAL  | \copybrief ROC_PARTIAL |
 * | \ref ROC_MANUAL   | \copybrief ROC_MANUAL  |
 *
 * \note Non-frontal faces detected by \ref ROC_FULL and \ref ROC_PARTIAL are
 *       \em not reliable for recognition.
 *       Therefore we advise against using \ref ROC_FULL or \ref ROC_PARTIAL in
 *       conjunction with \ref ROC_FR or \ref ROC_ID.
 *
 * \subsection representation_options Representation Options
 * <i>At most one</i> option should be specified to indicate the desired face
 * comparison mechanism.
 * If neither option is specified, \ref roc_template::fv_size will be zero and
 * the resulting \ref roc_template <i>can not</i> be used in
 * \ref roc_compare_templates or \ref roc_search.
 *
 * | Representation Options | Description               |
 * |------------------------|---------------------------|
 * | \ref ROC_FR            | \copybrief ROC_FR         |
 * | \ref ROC_ID            | \copybrief ROC_ID         |
 * | \em None               | No face comparison needed |
 *
 * \note A \ref ROC_FR template can \em not be compared to a \ref ROC_ID
 *       template.
 *
 * \subsection metadata_options Metadata Options
 * Each metadata option may be <i>optionally</i> included to add additional
 * fields to the \ref template_metadata.
 *
 * | Metadata Options   | Description                   |
 * |--------------------|-------------------------------|
 * | \ref ROC_PITCHYAW  | \copybrief ROC_PITCHYAW       |
 * | \ref ROC_GENDER    | \copybrief ROC_GENDER         |
 * | \ref ROC_AGE       | \copybrief ROC_AGE            |
 * | \ref ROC_OCCLUSION | \copybrief ROC_OCCLUSION      |
 * | \ref ROC_LIPS      | \copybrief ROC_LIPS           |
 * | \ref ROC_THUMBNAIL | \copybrief ROC_THUMBNAIL      |
 * | \em None           | No additional metadata needed |
 *
 * \subsection algorithm_id_examples Algorithm ID Examples
 * \code{C}
 * // Detect frontal faces and represent for controlled-capture comparison.
 * roc_algorithm_id algorithm_id = ROC_FRONTAL | ROC_ID;
 * \endcode
 * \code{C}
 * // Detect frontal faces, represent for in-the-wild comparison, and report
 * // gender and pose estimation.
 * roc_algorithm_id algorithm_id = ROC_FRONTAL | ROC_FR | ROC_GENDER | ROC_PITCHYAW;
 * \endcode
 * \code{C}
 * // Detect faces across all yaw ranges, report pose estimation, and construct
 * // a thumbnail.
 * roc_algorithm_id algorithm_id = ROC_FULL | ROC_PITCHYAW | ROC_THUMBNAIL;
 * \endcode
 *
 * \section minimum_size Minimum Size
 * The \p min_size parameter indicates the smallest face to detect in an image.
 * Face detection size is measured by the width of the face in pixels.
 * The suggested default value for \p min_size is \c 36, which corresponds
 * roughly to 18 pixels between the eyes.
 * A larger value for \p min_size will result in faster execution speed as less
 * time will be spent scanning the image for small faces.
 * While faces smaller than 36 pixels can be detected, they will be unreliable
 * for recognition.
 *
 * \subsection adaptive_minimum_size Adaptive Minimum Size
 * In the interest of efficiency, it is recommended to set an additional lower
 * bound on the minimum face size as a fraction of the image size.
 * An <i>adaptive minimum size</i> of 4% is computed as:
 *
 * \code{C}
 * size_t max(size_t x, size_t y) { return x > y ? x : y; }
 *
 * roc_image image = ...;
 * size_t minimumSize = ...;
 * minimumSize = max(minimumSize,
 *                   (size_t)(0.04 * max(image.width, image.height)));
 * \endcode
 *
 *
 * \section maximum_faces Maximum Faces
 * The \p k parameter indicates the maximum number of faces to detect in an
 * image.
 * This allows the function to return early without scanning the entire image if
 * it has found the requested number of faces.
 *
 * \section false_detection_rate False Detection Rate
 * The \p false_detection_rate parameter specifies the allowable false positive
 * rate for face detection.
 * The suggested default value for \p false_detection_rate is \c 0.02 which
 * corresponds to one false detection in 50 images on the
 * <a href="http://vis-www.cs.umass.edu/fddb/">FDDB</a> benchmark.
 * A higher false detection rate will correctly detect more faces at the cost of
 * also incorrectly detecting more non-faces.
 * The accepted range of values for \p false_accept_rate is \c 0.001 to \c 0.2.
 * Values outside this range will be truncated automatically.
 *
 * \section lazy_initialization Lazy Initialization
 * This first call to this function incurs additional overhead as the model
 * files needed to execute the specified \p algorithm_id are loaded from disk.
 * Call \ref roc_preload to avoid incuring this overhead on the first call.
 *
 * \par Example
 * \code{C}
 * roc_image image = ...;
 * roc_template templates[3];
 * roc_represent(image, ROC_FRONTAL | ROC_FR, 36, 3, 0.02f,
 *               (roc_template*) &templates);
 * \endcode
 *
 * \param[in] image Input image to process for faces.
 * \param[in] algorithm_id Algorithm identifier, see
 *                         \ref specifying_an_algorithm_id.
 * \param[in] min_size Minimum size face to detect, see \ref minimum_size.
 * \param[in] k The desired number of face templates, see \ref maximum_faces.
 * \param[in] false_detection_rate The lower bound for face detection
 *                                 confidence, see \ref false_detection_rate.
 * \param[out] templates Pre-allocated array to hold the generated templates.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_represent(roc_image image,
                                   roc_algorithm_id algorithm_id,
                                   size_t min_size,
                                   size_t k,
                                   float false_detection_rate,
                                   roc_template *templates);

/*!
 * \brief Call this function on a template after it is no longer needed.
 *
 * Frees the memory previously allocated for \ref roc_template::fv,
 * \ref roc_template::md, and \ref roc_template::tn.
 * Sets \ref roc_template::algorithm_id to \ref ROC_INVALID.
 * If \p template_ is \c NULL, this function does nothing.
 * \param[in,out] template_ The template to deallocate.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_free_template(roc_template *template_);

/** @} */ // end of template_generation

/*!
 * \defgroup template_io Template I/O
 * \brief Read and write templates.
 *
 * Serialize and deserialze templates to memory buffers with \ref roc_flatten
 * and \ref roc_unflatten.
 * Read and write templates using file pointers with \ref roc_read_template and
 * \ref roc_write_template, or file descriptors with \ref roc_read_template_fd
 * and \ref roc_write_template_fd.
 * Read and write template metadata with \ref roc_get_metadata and
 * \ref roc_set_metadata.
 *
 * @{
 */

/*!
  * \brief Serialize a template to a memory buffer.
  *
  * Use \ref roc_flattened_bytes to determine the appropriate size for
  * \p buffer.
  *
  * \par Example
  * \code{C}
  * roc_template template_ = ...;
  * size_t bytes = ...;
  * void *buffer = malloc(bytes);
  * roc_flatten(template_, buffer);
  * \endcode
  *
  * \param[in] template_ Template to serialize.
  * \param[out] buffer Pre-allocated buffer to hold the serialized template.
  * \remark This function is \ref reentrant.
  * \see \ref roc_unflatten
  */
ROC_EXPORT roc_error roc_flatten(const roc_template template_,
                                 uint8_t *buffer);

/*!
 * \brief Deserialize a template from a memory buffer.
 *
 * Free \p template_ after use with \ref roc_free_template.
 *
 * \par Example
 * \code{C}
 * void *buffer = ...;
 * roc_template template_;
 * roc_unflatten(buffer, &template_);
 * \endcode
 *
 * \param[in] buffer Buffer holding the serialized template.
 * \param[out] template_ Uninitialized address to hold the deserialized
 *                       template.
 * \remark This function is \ref reentrant.
 * \see \ref roc_flatten
 */
ROC_EXPORT roc_error roc_unflatten(const uint8_t *buffer,
                                   roc_template *template_);

/*!
 * \brief Calculate the bytes required to flatten a template.
 *
 * Use this function to determine the appropriate buffer size for
 * \ref roc_flatten.
 *
 * \par Example
 * \code{C}
 * roc_template template_ = ...;
 * size_t bytes;
 * roc_flattened_bytes(template_, &bytes);
 * \endcode
 *
 * \param[in] template_ Template to calculate the serialized size.
 * \param[out] bytes Bytes required to serialize the template.
 * \remark This function is \ref thread-safe.
 */
ROC_EXPORT roc_error roc_flattened_bytes(const roc_template template_,
                                         size_t *bytes);

/*!
 * \brief Read a template from a file pointer.
 *
 * Use this function to read from a \ref roc_gallery_file.
 * On success, \p file will be advanced to the end of \p template_.
 * If the \em end-of-file (EOF) is reached before reading a complete template,
 * \ref roc_template::algorithm_id will be set to \ref ROC_INVALID, \p file will
 * be reset to its original position, and the function will return without
 * error.
 *
 * Free \p template_ after use with \ref roc_free_template.
 *
 * \par Example
 * \code{C}
 * roc_template template_;
 * FILE *file = fopen("templates.t", "rb");
 * roc_read_template(file, &template_);
 * \endcode
 *
 * \param[in] file File to read from.
 * \param[out] template_ Pointer to unallocated template to construct.
 * \remark This function is \ref reentrant.
 * \see \ref roc_write_template
 */
ROC_EXPORT roc_error roc_read_template(FILE *file,
                                       roc_template *template_);

/*!
 * \brief Read a template from a file descriptor.
 *
 * Use this function to read from a \ref roc_gallery_file.
 * On success, \p file will be advanced to the end of \p template_.
 * If the \em end-of-file (EOF) is reached before reading a complete template,
 * \ref roc_template::algorithm_id will be set to \ref ROC_INVALID, \p file will
 * be reset to its original position, and the function will return without
 * error.
 *
 * Free \p template_ after use with \ref roc_free_template.
 *
 * \par Example
 * \code{C}
 * roc_template template_;
 * int fd = open("templates.t", O_RDONLY);
 * roc_read_template_fd(fd, &template_);
 * \endcode
 *
 * \param[in] fd File descriptor to read from.
 * \param[out] template_ Pointer to unallocated template to construct.
 * \remark This function is \ref reentrant.
 * \see \ref roc_write_template_fd
 */
ROC_EXPORT roc_error roc_read_template_fd(int fd,
                                          roc_template *template_);

/*!
 * \brief Write a template to a file pointer.
 *
 * Use this function to write to a \ref roc_gallery_file.
 * On success, \p file will be advanced to the end of \p template_.
 *
 * This function calls \c fwrite but not \c fflush.
 *
 * \par Example
 * \code{C}
 * roc_template template_ = ...;
 * FILE *file = fopen("templates.t", "wb");
 * roc_write_template(file, template_);
 * \endcode
 *
 * \param[in] file File to write to.
 * \param[out] template_ Template to write.
 * \remark This function is \ref reentrant.
 * \see \ref roc_read_template
 */
ROC_EXPORT roc_error roc_write_template(FILE *file,
                                        const roc_template template_);

/*!
 * \brief Write a template to a file descriptor.
 *
 * Use this function to write to a \ref roc_gallery_file.
 * On success, \p file will be advanced to the end of \p template_.
 *
 * This function calls \c write but not \c fsync.
 *
 * \par Example
 * \code{C}
 * roc_template template_ = ...;
 * int fd = fopen("templates.t", O_WRONLY);
 * roc_write_template_fd(fd, template_);
 * \endcode
 *
 * \param[in] fd File descriptor to write to.
 * \param[out] template_ Template to write.
 * \remark This function is \ref reentrant.
 * \see \ref roc_read_template_fd
 */
ROC_EXPORT roc_error roc_write_template_fd(int fd,
                                           const roc_template template_);

/*!
 * \brief Retrieve the value of for a metadata key.
 *
 * Template metadata is JSON formatted, see \ref template_metadata for details.
 * \param[in] template_ Template to retrieve the metadata value from.
 * \param[in] key Key to retrieve the value of.
 * \param[out] value Buffer to write the value to.
 * \param[in] value_length Length of \p value.
 * \see \ref roc_set_metadata
 */
ROC_EXPORT roc_error roc_get_metadata(const roc_template template_,
                                      const char *key,
                                      char *value,
                                      size_t value_length);

/*!
 * \brief Set, update, or remove a key/value pair in the metadata of a template.
 *
 * If \p value is NULL then \p key will be removed from the metadata.
 * After this function returns, the \ref roc_template::md field of \p template_
 * will point to a new string.
 *
 * Template metadata is JSON formatted, see \ref template_metadata for details.
 * \param[in,out] template_ Template to update the metadata of.
 * \param[in] key Metadata key to set.
 * \param[in] value Metadata value to set the key to.
 * \remark This function is \ref reentrant.
 * \see \ref roc_get_metadata
 */
ROC_EXPORT roc_error roc_set_metadata(roc_template *template_,
                                      const char *key,
                                      const char *value);

/** @} */ // end of template_io

/*!
 * \defgroup gallery_construction Gallery Construction
 * \brief Open, read, edit and close galleries.
 *
 * Open a \ref roc_gallery_file with \ref roc_open_gallery or
 * \ref roc_temporary_gallery, and close it with \ref roc_close_gallery.
 * Treat a gallery as a list of templates with \ref roc_enroll, \ref roc_size
 * and \ref roc_at, and \ref roc_remove.
 * Query the template limit with \ref roc_template_limit.
 *
 * @{
 */

/*!
 * \brief A contiguous array of templates written to disk.
 *
 * Iterate through templates in a gallery file using \ref roc_read_template and
 * \ref roc_write_template.
 * Open gallery files for analysis using \ref roc_open_gallery.
 */
typedef const char *roc_gallery_file;

/*!
 * \brief A list templates.
 *
 * Templates are held in memory for efficient search.
 *
 * Initialize with \ref roc_open_gallery, search with
 * \ref roc_search, and free with \ref roc_close_gallery.
 *
 * An immutable gallery is a \ref roc_const_gallery.
 */
typedef struct roc_gallery_type *roc_gallery;

/*!
 * \brief A constant \ref roc_gallery.
 */
typedef const struct roc_gallery_type *roc_const_gallery;

/*!
 * \brief Pointer to a callback function used to report progress on a long
 *        running task.
 *
 * The function should return \c void and take one \c float parameter which will
 * range from \c 0.0 to \c 100.0 indicating the percent completed.
 *
 * Any function taking a \ref roc_progress parameter will accept a \c NULL
 * value indicating not to report progress.
 *
 * \par Example
 * \code{C}
 * void print_progress(float percent_completed)
 * {
 *     printf("%.1f percent complete!\n", percent_completed);
 * }
 *
 * ...
 *
 * roc_gallery_file gallery_file = ...;
 * roc_gallery gallery;
 * roc_open_gallery(gallery_file, &gallery, &print_progress);
 *
 * // `roc_open_gallery` will periodically call `print_progress` indicating
 * // the percent completed.
 * \endcode
 */
typedef void (*roc_progress)(float);

/*!
 * \brief Open a gallery from a file.
 *
 * If \p gallery_file does not exist, an empty file will be created
 * automatically.
 * Release the gallery after use with \ref roc_close_gallery.
 *
 * \note The Android SDK only supports gallery files up to 2^31-1 bytes.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery;
 * roc_open_gallery("faces.t", &gallery, NULL);
 * \endcode
 *
 * \param[in] gallery_file File name to read/append templates from/to.
 * \param[out] gallery Address to store the opened gallery.
 * \param[in] progress Progress callback or \c NULL.
 * \remark This function is \ref reentrant.
 * \see \ref roc_temporary_gallery
 */
ROC_EXPORT roc_error roc_open_gallery(roc_gallery_file gallery_file,
                                      roc_gallery *gallery,
                                      roc_progress progress);

/*!
 * \brief Create a temporary gallery.
 *
 * Initialize an empty memory-only gallery.
 * Release the gallery after use with \ref roc_close_gallery.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery;
 * roc_temporary_gallery(&gallery);
 * \endcode
 *
 * \param[out] gallery Address to store the opened gallery.
 * \see \ref roc_open_gallery
 */
ROC_EXPORT roc_error roc_temporary_gallery(roc_gallery *gallery);

/*!
 * \brief Add a template to a gallery.
 *
 * This function is similar to \ref roc_write_template, appending the template
 * to the end of the corresponding \ref roc_gallery_file.
 * The enrolled template is now a potential candidate returned by
 * \ref roc_search.
 *
 * On platforms that support it, this function calls \c fsync on the gallery
 * file after writing \p template_.
 * Even if the application closes without calling \ref roc_close_gallery, the
 * biometric data will be preserved.
 *
 * Templates are stored in \p gallery akin to a \c std::vector.
 * The \ref roc_template_index of \p template_ in \p gallery will be equal the
 * \ref roc_size of \p gallery just prior to calling this function.
 *
 * To remove an enrolled template see \ref roc_remove.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_template template_ = ...;
 * roc_template_index template_index;
 * roc_size(gallery, &template_index);
 * roc_enroll(gallery, template_);
 * \endcode
 *
 * \param[in] gallery Gallery to add \p template_ to.
 * \param[in] template_ Template to add to \p gallery.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_enroll(roc_gallery gallery,
                                const roc_template template_);

/*!
 * \brief Retrieve the number of templates in a gallery.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * size_t size;
 * roc_size(gallery, &size);
 * \endcode
 *
 * \param[in] gallery The gallery to retrieve the number of templates.
 * \param[out] size The number of templates in \p gallery.
 * \remark This function is \ref thread-safe.
 * \see \ref roc_at
 */
ROC_EXPORT roc_error roc_size(roc_const_gallery gallery,
                              size_t *size);

/*!
 * \brief The index of a template in a gallery.
 *
 * Retrieve the corresponding template with \ref roc_at.
 * The value \ref ROC_INVALID_TEMPLATE_INDEX indicates an invalid template
 * index.
 */
typedef size_t roc_template_index;

/*!
 * \brief An invalid \ref roc_template_index.
 */
static const size_t ROC_INVALID_TEMPLATE_INDEX = ((roc_template_index) -1);

/*!
 * \brief Retrieve a template from a gallery at the specified index.
 *
 * This function returns a \em copy of the gallery template.
 * Free the copy after use with \ref roc_free_template.
 *
 * A gallery preserves the order of templates in its corresponding
 * \ref roc_gallery_file.
 *
 * This function is exposed in the \ref cli as \ref roc-at.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_template_index index = ...;
 * roc_template template_;
 * roc_at(gallery, index, &template_);
 * \endcode
 *
 * \param[in] gallery The gallery to retrieve a template from.
 * \param[in] index The index of the template, between 0 and
 *                  (\ref roc_size - 1).
 * \param[out] template_ A copy of the template in \p gallery at \p index.
 * \remark This function is \ref thread-safe.
 * \see \ref roc_size
 */
ROC_EXPORT roc_error roc_at(roc_const_gallery gallery,
                            roc_template_index index,
                            roc_template *template_);

/*!
 * \brief Remove the template at the specified index.
 *
 * For efficiency purposes, this function will replace the removed template with
 * an \ref empty_template.
 * Therefore \ref roc_size will remain the same, as will the
 * \ref roc_template_index of the remaining templates.
 *
 * This function is exposed in the \ref cli as \ref roc-remove.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_remove(gallery, 3);
 * \endcode
 *
 * \param[in] gallery Gallery to remove template from.
 * \param[in] index Index of the template to remove.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_remove(roc_gallery gallery,
                                roc_template_index index);

/*!
 * \brief Close an open gallery.
 *
 * This will free memory associated with \p gallery.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_close_gallery(gallery);
 * \endcode
 *
 * \param[in] gallery The gallery to close.
 * \remark This function is \ref reentrant.
 * \see \ref roc_open_gallery
 */
ROC_EXPORT roc_error roc_close_gallery(roc_gallery gallery);

/*!
 * \brief Query the remaining template limit.
 *
 * Most licenses of the ROC SDK include a limit on the number of templates that
 * can be used at once.
 * The number of templates in use is the sum of \ref roc_size for all galleries
 * in use.
 * This function returns the number of templates specified in the license file
 * \em less the number of templates in use.
 *
 * \par Example
 * \code{C}
 * size_t template_limit;
 * roc_template_limit(&template_limit);
 * \endcode
 *
 * \param[out] template_limit The remaining number of templates available.
 * \remark This function is \ref thread-safe.
 */
ROC_EXPORT roc_error roc_template_limit(size_t *template_limit);

/** @} */ // end of gallery_construction

/*!
 * \defgroup comparison Comparison
 * \brief Compare face templates.
 *
 * Measure the \ref roc_similarity between individual face templates with
 * \ref roc_compare_templates or galleries with \ref roc_compare_galleries.
 *
 * @{
 */

/*!
 * \brief A measurement between two faces quantifying the psuedo-probability
 *        that they originated from the same person.
 *
 * Similarity scores fall in the range <tt>[0, 1]</tt> with larger values
 * indicating greater similarity.
 *
 * Similarity is always measured between the \ref feature_vector component of
 * two templates without consideration of any other potential sources of
 * information.
 *
 * \section calculating_false_match_rates Calculating False Match Rates
 * Similarity scores are normalized against an impostor score distribution as
 * follows:
 * - The mean impostor comparison is assigned a similarity score of \c 0.2.
 * - A change in similarity score of \c 0.1 represents a one standard deviation
 *   shift from the mean impostor comparison.
 * - Similarity scores outside the <tt>[0, 1]</tt> range are truncated into the
 *   range.
 *
 * | Similarity Threshold | Approximate False Match Rate   |
 * |----------------------|--------------------------------|
 * | 0.2                  | 1 in 2                         |
 * | 0.3                  | 1 in 6                         |
 * | 0.328                | 1 in 10                        |
 * | 0.4                  | 1 in 44                        |
 * | 0.433                | 1 in 100                       |
 * | 0.5                  | 1 in 740                       |
 * | 0.509                | 1 in 1,000                     |
 * | 0.572                | 1 in 10,000                    |
 * | 0.6                  | 1 in 32,000                    |
 * | 0.626                | 1 in 100,000                   |
 * | 0.675                | 1 in 1,000,000                 |
 * | 0.7                  | 1 in 3,500,000                 |
 * | 0.720                | 1 in 10,000,000                |
 * | 0.761                | 1 in 100,000,000               |
 * | 0.8                  | 1 in 1,000,000,000             |
 *
 * In [<tt>R</tt>](https://www.r-project.org/) you can convert between a false
 * match rate \a fmr and a similarity threshold \a st as follows:
 *
 * \code
 * fmr = 1-pnorm(  st , mean=0.2, sd=0.1)
 * st  =   qnorm(1-fmr, mean=0.2, sd=0.1)
 * \endcode
 *
 * \section functions_that_measure_similarity Functions That Measure Similarity
 * The following functions all measure similarity in the same way, but offer
 * interfaces tailored to different use cases.
 *
 * | Function                         | Description                      |
 * |----------------------------------|----------------------------------|
 * | \ref roc_compare_templates       | \copybrief roc_compare_templates |
 * | \ref roc_compare_galleries       | \copybrief roc_compare_galleries |
 * | \ref roc_search                  | \copybrief roc_search            |
 * | \ref roc_knn                     | \copybrief roc_knn               |
 */
typedef float roc_similarity;

/*!
 * \brief An invalid \ref roc_similarity.
 */
#define ROC_INVALID_SIMILARITY (-FLT_MAX)

/*!
 * \brief Measure the similarity between two templates.
 *
 * Higher scores indicate greater similarity.
 * This function is a specialized version of \ref roc_compare_galleries.
 *
 * \note Comparisons involving many templates should make use of the other
 * \ref functions_that_measure_similarity as they will be much faster than
 * making repeated calls this this function.
 *
 * \section symmetry Symmetry
 * The returned \p similarity score is \em symmetric.
 * In other words, swapping the order of \p a and \p b will not change
 * \p similarity.
 *
 * \section empty_template Empty Template
 * A template is said to be \a empty if it has a \c NULL feature vector.
 * By convention, a comparison involving one or both empty templates results in
 * a \p similarity of 0.
 *
 * \par Example
 * \code{C}
 * roc_template a = ...;
 * roc_template b = ...;
 * roc_similarity similarity;
 * roc_compare_templates(a, b, &similarity);
 * \endcode
 *
 * \param[in] a The first template to compare.
 * \param[in] b The second template to compare.
 * \param[out] similarity Similarity between \p a and \p b.
 * \remark This function is \ref thread-safe.
 */
ROC_EXPORT roc_error roc_compare_templates(const roc_template a,
                                           const roc_template b,
                                           roc_similarity *similarity);

/*!
 * \brief Measure the pairwise similarity between all templates in two
 *        galleries.
 *
 * This function is a generalized version of \ref roc_compare_templates and is
 * exposed in the \ref cli as \ref roc-compare.
 *
 * When \p a and \p b refer to the same gallery, \p similarities is called a
 * <i>self-similarity matrix</i>.
 *
 * \par Example
 * \code{C}
 * roc_gallery target = ...;
 * roc_gallery query = ...;
 * size_t target_size, query_size;
 * roc_size(target, &target_size);
 * roc_size(query, &query_size);
 * roc_similarity *similarity_matrix = (roc_similarity*) malloc(target_size *
 *                                                              query_size *
 *                                                      sizeof(roc_similarity));
 * roc_compare_galleries(a, b, similarities);
 * \endcode
 *
 * \param[in] target Gallery whose templates constitute the columns in
 *                   \p similaries.
 * \param[in] query Gallery whose templates constitute the rows in
 *                  \p similarities.
 * \param[out] similarity_matrix Buffer large enough to hold
 *                               <tt>roc_size(target) * roc_size(query)</tt>
 *                               similarity scores, populated in row-major
 *                               order.
 * \remark This function is \ref thread-safe.
 */
ROC_EXPORT roc_error roc_compare_galleries(roc_const_gallery target,
                                           roc_const_gallery query,
                                           roc_similarity *similarity_matrix);

/** @} */ // end of comparison

/*!
 * \defgroup search Search
 * \brief Search a gallery.
 *
 * Retrieve a sorted list of the top candidate templates for a single probe with
 * \ref roc_search or multiple independent probes with \ref roc_knn.
 * Re-order search results based on commonly occuring \ref roc_person_id with
 * \ref roc_rerank.
 *
 * @{
 */

/*!
 * \brief Reference to a gallery template associated with a similarity to a
 *        probe.
 *
 * Retrieve the gallery template using \ref roc_at with
 * \ref roc_candidate::index.
 * Note that \ref roc_candidate::similarity is equal to the similarity returned
 * by \ref roc_compare_templates.
 */
typedef struct roc_candidate
{
    roc_template_index index; /*!< \brief Index of the candidate template in the
                                          gallery. */
    roc_similarity similarity; /*!< \brief Similarity of the candidate template
                                           to the probe. */
} roc_candidate;

/*!
 * \brief Ranked search for a probe template against a gallery of templates.
 *
 * The pre-allocated buffer \p candidates should be large enough to contain \p k
 * elements.
 * The \p candidates will be ordered by decreasing
 * \ref roc_candidate::similarity.
 * In the event that there are fewer than \p k candidates to return, the
 * trailing elements of \p candidates will be populated with
 * \ref roc_candidate::index of \ref ROC_INVALID_TEMPLATE_INDEX and
 * \ref roc_candidate::similarity of \ref ROC_INVALID_SIMILARITY.
 *
 * Note that this function is a special case of \ref roc_knn with a single
 * probe template and is exposed in the \ref cli as \ref roc-search.
 *
 * If you have multiple probes, it is more efficient to call \ref roc_knn once
 * than make repeated calls to \ref roc_search.
 * This is particularly especially when \p gallery is large as the probes will
 * be batched together to minimize reads to main memory.
 *
 * \section number_of_candidates Number of Candidates
 * The \p k most similar templates in \p gallery to \p probe, ordered by
 * decreasing similarity.
 * The suggested default value for \p k is 20.
 *
 * \section min_search_similarity Minimum Similarity
 * The minimum similarity score required to add a candidate to the candidate
 * list.
 * The suggested default value for \p min_similarity is 0.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_template probe = ...;
 * roc_candidate candidates[20];
 * roc_search(gallery, probe, 20, 0, (roc_candidate*) &candidates);
 * \endcode
 *
 * \param[in] gallery Gallery to search against.
 * \param[in] probe Template to search for.
 * \param[in] k The desired number of candidates, see \ref number_of_candidates.
 * \param[in] min_similarity The desired minimum similarity of candidates, see
 *                           \ref min_search_similarity.
 * \param[out] candidates Pre-allocated buffer to contain the top matching
 *                        templates in \p gallery.
 * \remark This function is \ref thread-safe.
 * \see \ref roc_compare_galleries \ref roc_rerank
 */
ROC_EXPORT roc_error roc_search(roc_const_gallery gallery,
                                const roc_template probe,
                                size_t k,
                                roc_similarity min_similarity,
                                roc_candidate *candidates);

/*!
 * \brief Construct the k-nearest neighbors graph of a gallery.
 *
 * The pre-allocated buffer \p neighbors should be large enough to hold
 * <tt>n = k*\ref roc_size (probes)</tt> elements.
 * For a \ref roc_template_index \c ti_p in \p probes, its <tt>i</tt>-th nearest
 * neighbor in \p gallery is <tt>ti_g = neighbors[ti_p*k+i]</tt>.
 *
 * In the common case where <tt>gallery == probe</tt>, \p neighbors can be used
 * as the input to \ref roc_cluster.
 *
 * This function is a generalized version of \ref roc_search with multiple
 * independent probe templates.
 *
 * \section nearest_neighbors Nearest Neighbors
 * The \p k nearest neighbors to a template are the \p k most similar templates
 * in \p gallery to it, ordered by decreasing similarity.
 * The suggested default value for \p k is \c 20.
 *
  * \section min_knn_similarity Minimum Similarity
 * The minimum similarity score required to add a candidate to the nearest
 * neighbors graph.
 * The suggested default value for \p min_similarity is 0.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * size_t k = ...;
 * size_t size;
 * roc_size(gallery, &size)
 * roc_candidate *neighbors = (roc_candidate*) malloc(k * size *
 *                                                    sizeof(roc_candidate));
 * roc_knn(gallery, gallery, k, neighbors);
 * \endcode
 *
 * \param[in] gallery The templates from which to find nearest neighbors.
 * \param[in] probes The templates for which to find nearest neighbors.
 * \param[in] k The number of nearest neighbors in \p gallery to retain, see
 *              \ref nearest_neighbors.
 * \param[in] min_similarity The desired minimum similarity of candidates, see
 *                           \ref min_knn_similarity.
 * \param[out] neighbors Pre-allocated buffer to store the nearest neighbors of
 *                       each template in \p probes.
 * \remark This function is \ref thread-safe.
 * \see \ref roc_search \ref roc_rerank
 */
ROC_EXPORT roc_error roc_knn(roc_const_gallery gallery,
                             roc_const_gallery probes,
                             size_t k,
                             roc_similarity min_similarity,
                             roc_candidate *neighbors);

/*!
 * \brief Re-rank \ref roc_search results based on commonly occuring
 *        \ref roc_person_id.
 *
 * \ref roc_search and \ref roc_knn order each \ref roc_candidate independently
 * based soley on its \ref roc_similarity score to the probe \ref roc_template.
 * This function re-orders \p candidates by additionally considering commonly
 * occuring \ref roc_template::person_id.
 * In the resulting \p candidates, two \ref roc_candidate with the same
 * \ref roc_template::person_id will occur at adjacent indicies.
 * This function has no effect when \p candidates have unique or
 * \ref ROC_UNKNOWN_PERSON values for \ref roc_person_id.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_template probe = ...;
 * roc_candidate candidates[20];
 * roc_search(gallery, probe, 20, 0, (roc_candidate*) &candidates);
 * roc_rerank(gallery, 20, (roc_candidate*) &candidates);
 * \endcode
 *
 * \param[in] gallery The gallery used in the prior call to \ref roc_search or
 *                    \ref roc_knn.
 * \param[in] k The length of \p candidates used in the prior call to
 *              \ref roc_search or \ref roc_knn.
 * \param[in,out] candidates Candidates list to re-order based on commonly
 *                           occuring \ref roc_template::person_id.
 * \remark This function is \ref thread-safe.
 * \see \ref roc_search \ref roc_knn
 */
ROC_EXPORT roc_error roc_rerank(roc_const_gallery gallery,
                                size_t k,
                                roc_candidate *candidates);

/** @} */ // end of search

/*!
 * \defgroup identity_discovery Identity Discovery
 * \brief Group a gallery into identities.
 *
 * Identities are managed using the \ref roc_template::person_id field.
 * Cluster faces into identities with \ref roc_cluster.
 * Track faces in a video with \ref roc_track.
 * Downsample identities with \ref roc_consolidate.
 * Retrieve identities from a gallery with \ref roc_person_ids.
 *
 * @{
 */

/*!
 * \brief Construct clusters from a k-nearest neighbors graph.
 *
 * Clustering groups templates by similarity.
 * Clustering results are stored persistently in the
 * \ref roc_template::person_id field for each template in \p gallery, and can
 * be retrieved with \ref roc_person_ids.
 * Clusters are sorted by a combination of quality and size, with the largest
 * and most internally similar cluster assigned a \ref roc_template::person_id
 * of zero.
 *
 * The input to this function is the output from \ref roc_knn.
 *
 * This function is exposed in the \ref cli as \ref roc-cluster.
 *
 * \section aggressiveness Aggressiveness
 * The clustering \p aggressiveness is a value in the range <tt>[-1.0, 1.0]</tt>
 * that influences the number of clusters formed.
 * A value toward \c -1.0 favors more clusters (fewer templates per cluster).
 * Conversely, a value toward \c 1.0 favors fewer clusters (more templates per
 * cluster).
 * The suggested default value for \p aggressiveness is \c 0.0.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * size_t k = ...;
 * roc_candidate *neighbors = ...;
 * roc_cluster(gallery, k, neighbors, 0.0);
 * \endcode
 *
 * \param[in,out] gallery The gallery used to construct \p neighbors.
 * \param[in] k Number of nearest neighbors kept for each template in
 *              \p neighbors.
 * \param[in] neighbors Nearest neighbor graph computed from \ref roc_knn with
 *                      \p gallery.
 * \param[in] aggressiveness Clustering aggressiveness, see \ref aggressiveness.
 * \remark This function is \ref reentrant.
 * \see \ref roc_track
 */
ROC_EXPORT roc_error roc_cluster(roc_gallery gallery,
                                 size_t k,
                                 const roc_candidate *neighbors,
                                 float aggressiveness);

/*!
 * \brief Track faces across frames in a video.
 *
 * This is an alternative clustering algorithm that groups templates based on
 * temporal, spatial and facial similarity.
 * Two templates are assigned the same \ref roc_template::person_id if all of
 * the following are true:
 *  - Their roc_template::timestamp absolute difference is less than or equal
 *    to \p max_time_separation (and greater than zero).
 *    The suggested default value for \p max_time_separation is \c 1000,
 *    corresponding to a one second separation for videos with thirty frames
 *    per second.
 *  - Their detection intersection area divided by union area, or \a overlap,
 *    is greater than or equal to \p min_detection_overlap.
 *    The suggested default value for \p min_detection_overlap is \c 0.5.
 *  - Their facial similarity is greater than or equal to \p min_similarity.
 *    The suggested default value for \p min_similarity is \c 0.5.
 *
 * All templates in the gallery are assumed to belong to the same video.
 *
 * Tracking results are stored persistently in the \ref roc_template::person_id
 * field for each template in \p gallery, and can be retrieved with
 * \ref roc_person_ids.
 *
 * This function is exposed in the \ref cli as \ref roc-track.
 *
 * \section max_time_separation Maximum Time Separation
 * The maximum absolute time difference, greater than zero.
 *
 * \section min_detection_overlap Minimum Detection Overlap
 * The minimum face detection bounding box overlap, between zero and one
 * inclusive.
 *
 * \section min_track_similarity Minimum Similarity
 * Minimum template similarity, between zero and one inclusive.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_track(gallery, 1000, 0.5, 0.5);
 * \endcode
 *
 * \param[in,out] gallery The gallery to track.
 * \param[in] max_time_separation Maximum absolute time difference, see
 *                                 \ref max_time_separation.
 * \param[in] min_detection_overlap Minimum face detection bounding box overlap,
 *                                  see \ref min_detection_overlap.
 * \param[in] min_similarity Minimum template similarity, see
 *                           \ref min_track_similarity.
 * \remark This function is \ref reentrant.
 * \see \ref roc_cluster
 */
ROC_EXPORT roc_error roc_track(roc_gallery gallery,
                               roc_time max_time_separation,
                               float min_detection_overlap,
                               roc_similarity min_similarity);

/*!
 * \brief Downsample a gallery by selecting representative templates for each
 *        \ref roc_template::person_id.
 *
 * For each set of templates with the same \ref roc_template::person_id in
 * \p gallery, this function greedily removes the "most redundant template"
 * until \em both of the following conditions are met:
 *  - The maximum pairwise similarity between all remaining templates is less
 *    than or equal to \p max_similarity. See \ref max_similarity.
 *  - The number of remaining templates is less than or equal to \p max_count.
 *    See \ref max_count.
 *
 * Templates with \ref roc_template::person_id == \ref ROC_UNKNOWN_PERSON in
 * \p are retained automatically.
 * This function is generally called after \ref roc_cluster or \ref roc_track
 * to discard superfluous templates.
 *
 * Consolidation results are stored persistently in the
 * \ref roc_template::person_id field for each template in \p gallery, and can
 * be retrieved with \ref roc_person_ids.
 *
 * This function is exposed in the \ref cli as \ref roc-consolidate.
 *
 * \note This function removes templates from \p gallery.
 *
 * \section max_similarity Maximum Similarity
 * The maximum pairwise similarity between templates in a consolidated identity,
 * between zero and one inclusive.
 * After consolidation no two templates belonging to the same person will
 * have a similarity score greater than \p max_similarity.
 * The suggested default value for \p max_similarity is \c 0.9.
 *
 * \section max_count Maximum Count
 * The maximum number of templates in a consolidated identity, greater than
 * zero.
 * After consolidation no person will have more than \p max_count templates.
 * The suggested default value for \p max_count is \c 5.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * roc_consolidate_gallery(gallery, 0.9, 5);
 * \endcode
 *
 * \param[in,out] gallery The gallery containing the identities to consolidate.
 * \param[in] max_similarity The maximum pairwise similarity per person, see
 *                           \ref max_similarity.
 * \param[in] max_count The maximum number of templates per person, see
 *                      \ref max_count.
 * \remark This function is \ref reentrant.
 */
ROC_EXPORT roc_error roc_consolidate(roc_gallery gallery,
                                     roc_similarity max_similarity,
                                     size_t max_count);

/*!
 * \brief Retrieve the \ref roc_template::person_id for each template in a
 *        gallery.
 *
 * Used to obtain the results of a call to \ref roc_cluster, \ref roc_track,
 * \ref roc_consolidate.
 *
 * The \ref roc_person_id at index \c i in \p person_ids corresponds to the
 * <tt>i</tt>th template in \p gallery, retrievable by \ref roc_at.
 *
 * \par Example
 * \code{C}
 * roc_gallery gallery = ...;
 * size_t size;
 * roc_size(gallery, &size)
 * roc_person_id *person_ids = (roc_person_id*) malloc(size *
 *                                                     sizeof(roc_person_id));
 * roc_person_ids(gallery, person_ids);
 * \endcode
 *
 * \param[in] gallery The gallery to retrieve the \ref roc_template::person_id
 *                    list from.
 * \param[out] person_ids The \ref roc_template::person_id for each template in
 *                        \p gallery.
 * \remark This function is \ref thread-safe.
 */
ROC_EXPORT roc_error roc_person_ids(roc_const_gallery gallery,
                                    roc_person_id *person_ids);

/** @} */ // end of identity_discovery

#ifdef __cplusplus
}
#endif

#endif // ROC_H
