#!/bin/bash

# Default values
IMAGE_TAG="ros2-humble-simulation:latest"
CONTAINER_NAME="ros2-humble-simulation-container"

# Parse command line arguments
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -i|--image)
            IMAGE_TAG="$2"
            shift
            ;;
        -n|--name)
            CONTAINER_NAME="$2"
            shift
            ;;
        --help)
            echo "Usage: $0 [-i image_tag] [-n container_name] [--help]"
            echo "  -i, --image       Set the Docker image tag to use (default: ${IMAGE_TAG})"
            echo "  -n, --name        Set the Docker container name (default: ${CONTAINER_NAME})"
            echo "  --help            Display this help message"
            exit 0
            ;;
        *)
            echo "Unknown parameter: $1"
            exit 1
            ;;
    esac
    shift
done

# Allow X11 forwarding
xhost +

# Run the Docker container
echo -e "\033[0;32mStarting Docker container '${CONTAINER_NAME}' with image '${IMAGE_TAG}'...\033[0m"
docker run --gpus all --name "${CONTAINER_NAME}" -it --rm --network=host \
    -v $HOME/.Xauthority:/root/.Xauthority \
    -e DISPLAY \
    -v "$(pwd)/ros_ws:/workstation/ros_ws" \
    --ipc=host "${IMAGE_TAG}"

echo -e "\033[0;32mContainer '${CONTAINER_NAME}' has stopped.\033[0m"

