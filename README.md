# pyApproxMVBB

This is a **very rudimentary** python binding to the [ApproxMVBB library by gabyx](https://github.com/gabyx/ApproxMVBB). The need for this arose due to the fact that a project of mine required a close-to-minimum-volume OBB function for point clouds and [pyobb](https://github.com/pboechat/pyobb) did poorly for my data.

The binding only supports building an oriented bounding box from a numpy matrix of points, which in turn only consists of a function returning the eight corner points in the global coordinate system. Check out pyobb first before using this, as it is far more stable. If your data describes a lot of symmetrical rectangular shapes like mine, ApproxMVBB might be worth a try since it appears to outperform pyobb in these cases.

## Usage

The core functionality is the `approximateMVBB` call. The parameters of the function are the same as in the original implementation, so check out [the original project](https://github.com/gabyx/ApproxMVBB) to learn what the individual parameters do. Other than that, a simple call to `getCornerPoints()` returns a representation of the bounding box as a list of corner point vectors (numpy arrays). The pointcloud needs to be represented as a numpy array of shape (3, n) and data type float64 with every column being a point of the pointcloud.

```python
import pyApproxMVBB as ap

# Generate the pointcloud, convert it to a numpy array ...
# Choose parameters eps, ps, gs, dol, gsol, sd ...

oobb = ap.approximateMVBB(pts=pointcloud, epsilon=eps, pointSamples=ps, gridSize=gs, mvbbDiamOptLoops=dol, mvbbGridSearchOptLoops=gsol, seed=sd)
cornerpoints = oobb.getCornerPoints()

# Use corner points for further computation ...

```

## Building

**Warning: The following has only been tested under Arch Linux using Python 3.6 under pyenv, your mileage may vary.**

The binding relies on [pybind11](https://github.com/pybind/pybind11), which is already added as a submodule to the project and will be built automatically. Just make sure to git init and update the submodule first.

Additionally, ApproxMVBB needs to be installed on your system. For information on how to build it check out its [GitHub page](https://github.com/gabyx/ApproxMVBB).

Once pybind11 is cloned and ApproxMVBB is installed, a simple setup call should do the trick:
`python setup.py install`

## Results

Exemplary oriented bounding boxes for the individual parts of a chair pointcloud:

![example.png](https://github.com/Novare/pyApproxMVBB/blob/master/images/example.png)

## Licensing

In accordance to the original ApproxMVBB project, the source code is released under MPL 2.0.
