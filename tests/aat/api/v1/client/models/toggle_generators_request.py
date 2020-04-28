# coding: utf-8

"""
    OpenPerf API

    REST API interface for OpenPerf  # noqa: E501

    OpenAPI spec version: 1
    Contact: support@spirent.com
    Generated by: https://github.com/swagger-api/swagger-codegen.git
"""


import pprint
import re  # noqa: F401

import six


class ToggleGeneratorsRequest(object):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """

    """
    Attributes:
      swagger_types (dict): The key is attribute name
                            and the value is attribute type.
      attribute_map (dict): The key is attribute name
                            and the value is json key in definition.
    """
    swagger_types = {
        'replace': 'str',
        '_with': 'str'
    }

    attribute_map = {
        'replace': 'replace',
        '_with': 'with'
    }

    def __init__(self, replace=None, _with=None):  # noqa: E501
        """ToggleGeneratorsRequest - a model defined in Swagger"""  # noqa: E501

        self._replace = None
        self.__with = None
        self.discriminator = None

        self.replace = replace
        self._with = _with

    @property
    def replace(self):
        """Gets the replace of this ToggleGeneratorsRequest.  # noqa: E501

        The unique id of the running generator  # noqa: E501

        :return: The replace of this ToggleGeneratorsRequest.  # noqa: E501
        :rtype: str
        """
        return self._replace

    @replace.setter
    def replace(self, replace):
        """Sets the replace of this ToggleGeneratorsRequest.

        The unique id of the running generator  # noqa: E501

        :param replace: The replace of this ToggleGeneratorsRequest.  # noqa: E501
        :type: str
        """
        self._replace = replace

    @property
    def _with(self):
        """Gets the _with of this ToggleGeneratorsRequest.  # noqa: E501

        The unique id of the stopped generator  # noqa: E501

        :return: The _with of this ToggleGeneratorsRequest.  # noqa: E501
        :rtype: str
        """
        return self.__with

    @_with.setter
    def _with(self, _with):
        """Sets the _with of this ToggleGeneratorsRequest.

        The unique id of the stopped generator  # noqa: E501

        :param _with: The _with of this ToggleGeneratorsRequest.  # noqa: E501
        :type: str
        """
        self.__with = _with

    def to_dict(self):
        """Returns the model properties as a dict"""
        result = {}

        for attr, _ in six.iteritems(self.swagger_types):
            value = getattr(self, attr)
            if isinstance(value, list):
                result[attr] = list(map(
                    lambda x: x.to_dict() if hasattr(x, "to_dict") else x,
                    value
                ))
            elif hasattr(value, "to_dict"):
                result[attr] = value.to_dict()
            elif isinstance(value, dict):
                result[attr] = dict(map(
                    lambda item: (item[0], item[1].to_dict())
                    if hasattr(item[1], "to_dict") else item,
                    value.items()
                ))
            else:
                result[attr] = value
        if issubclass(ToggleGeneratorsRequest, dict):
            for key, value in self.items():
                result[key] = value

        return result

    def to_str(self):
        """Returns the string representation of the model"""
        return pprint.pformat(self.to_dict())

    def __repr__(self):
        """For `print` and `pprint`"""
        return self.to_str()

    def __eq__(self, other):
        """Returns true if both objects are equal"""
        if not isinstance(other, ToggleGeneratorsRequest):
            return False

        return self.__dict__ == other.__dict__

    def __ne__(self, other):
        """Returns true if both objects are not equal"""
        return not self == other