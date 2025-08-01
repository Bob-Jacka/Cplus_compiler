from collections import OrderedDict
from core.functional.Settings import (
    leaky_relu_value,
)
from core.functional.Utils import print_error, print_success
from torch import Tensor
from torch.nn import (
    Conv2d,
    Linear,
    Sequential,
    LeakyReLU,
    MaxPool2d,
    Dropout2d,
    Parameter,
    Module
)
from typing import Iterator, Literal


class Neuro_block(Module):
    """
    Class for one neuro block, can be convolutional or linear.
    Implements nn.Module.
    Contains methods for constructing Linear or Conv neural networks.
    """

    nb_kernel_size: int
    """
    Kernel size of the neuro block.
    """

    dropout_rate: float
    """
    Dropout rate for dropout layer of neuro block.
    """

    create_class: str
    """
    Which class to be created.
    Equals only Conv2d or Linear.
    """

    inner_structure: Sequential
    """
    Inner structure of neuro block.
    """

    def __init__(self, sizes: tuple[int, int] | list[int, int], input_dropout_rate: float,
                 class_to_create: Literal['Conv2d', 'Linear', 'Dense'], kernel_size: int = 3,
                 padding: int = 1, stride: int = 1, bias: bool = True, *args, **kwargs):
        """
        Constructor for neuro block with different layers.
        :param sizes: 2 value tuple, where first element is width of image and second value is height.
        :param input_dropout_rate: values in tensors with this float number will be cut off.
        :param kernel_size: size of window to compute. By default, equals 3.
        :param: padding:
        :param class_to_create torch classes of models to create, can be one of ... .
        :param args: None.
        :param kwargs: None.
        """
        super().__init__(*args, **kwargs)
        self.dropout_rate = input_dropout_rate
        self.nb_kernel_size = kernel_size
        self.padding = padding
        self.create_class = class_to_create
        if class_to_create == 'Conv2d':
            self.__create_conv_layer__(
                input_count=sizes[0],
                output_count=sizes[1],
                kernel_size=kernel_size,
                padding=padding,
                stride=stride,
                bias=bias,
                dropout_rate=input_dropout_rate
            )
        elif class_to_create == 'Linear':
            self.__create_linear_layer__(
                input_count=sizes[0],
                output_count=sizes[1],
                dropout_rate=input_dropout_rate,
                bias=bias,
                percentage_to_reduce=1
            )
        else:
            print_error(
                f'Error occurred, expecting types Conv2d, Linear or Dense, got {type(class_to_create)} instead.')

    def __create_conv_layer__(self, input_count: int, output_count: int, kernel_size: int, stride: int, padding: int,
                              bias: bool, dropout_rate: float):
        """
        *Private method of class*.
        Creates convolutional network with given parameters.
        :param input_count: input count of connections.
        :param output_count: output count of connections.
        :param dropout_rate: drop out rate for Dropout layer, cut off this value from input flow.
        :param kernel_size: size of window to compute.
        :return: convolutional layer in inner structure.
        """
        self.inner_structure = Sequential(
            OrderedDict([
                ('input_conv',
                 Conv2d(in_channels=input_count, out_channels=output_count, kernel_size=kernel_size, padding=padding,
                        stride=stride, bias=bias)),
                ('l_relu', LeakyReLU(leaky_relu_value)),
                ('maxPool_layer', MaxPool2d(kernel_size=kernel_size + 1, stride=stride)),
                ('drop_layer', Dropout2d(p=dropout_rate))
            ])
        )
        print_success('Conv network created.')

    def __create_linear_layer__(self, input_count: int, output_count: int, bias: bool, dropout_rate: float,
                                percentage_to_reduce: int):
        """
        *Private method of class*.
        Creates Linear network with given parameters.
        :param input_count: input count of connections.
        :param output_count: output count of connections.
        :param bias: bool value of structure bias.
        :param dropout_rate: drop out rate for Dropout layer, cut off this value from input flow.
        :return: linear layer in inner structure.
        """
        self.inner_structure = Sequential(
            OrderedDict([
                ('linear1', Linear(input_count, output_count, bias=bias)),
                ('drop_layer', Dropout2d(p=dropout_rate)),
            ]),
        )
        print_success('Linear network created.')

    def get_parameters(self) -> Iterator[Parameter]:
        """
        Method for receiving NeuroBlock parameters.
        :return: Iterator with parameters.
        """
        return self.parameters()

    def forward(self, x: Tensor):
        """
        Inner torch function for computing.
        :param x: input tensor
        :return: nothing.
        """
        return self.inner_structure(x)
