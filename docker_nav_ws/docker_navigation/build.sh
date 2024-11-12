#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Get the directory of the current script and project root
SCRIPT_DIR="$(cd "$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")" &>/dev/null && pwd)"
PROJECT_DIR="$(dirname "${SCRIPT_DIR}")"

# Docker image tag and Dockerfile path
TAG="ros2-humble-nav2_ws"
DOCKERFILE="${SCRIPT_DIR}/Dockerfile"

# Display usage information
function usage() {
    echo "Usage: $0 [-t tag] [--no-cache]"
    echo "  -t, --tag       Set the Docker image tag (default: ${TAG})"
    echo "  --no-cache      Build the Docker image without using cache"
    exit 1
}

# Parse command line arguments
NO_CACHE=""
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -t|--tag)
            TAG="$2"
            shift
            ;;
        --no-cache)
            NO_CACHE="--no-cache"
            ;;
        -h|--help)
            usage
            ;;
        *)
            echo "Unknown parameter: $1"
            usage
            ;;
    esac
    shift
done

# Build the Docker image
DOCKER_BUILD_CMD=(docker build "${SCRIPT_DIR}" --tag "${TAG}" -f "${DOCKERFILE}" ${NO_CACHE})

echo -e "\033[0;32mBuilding Docker image with the following command:\033[0m"
echo "${DOCKER_BUILD_CMD[*]}"

# Execute the build command
"${DOCKER_BUILD_CMD[@]}"

echo -e "\033[0;32mDocker image '${TAG}' built successfully.\033[0m"
