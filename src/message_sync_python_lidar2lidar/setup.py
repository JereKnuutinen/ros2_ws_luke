from setuptools import setup

package_name = 'message_sync_python_lidar2lidar'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mlemsalu',
    maintainer_email='jere.knuutinen@hotmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'sync_msg_lidars = message_sync_python_lidar2lidar.sync_msg_lidars:main'
        ],
    },
)
