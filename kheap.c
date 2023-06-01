#include <inc/memlayout.h>
#include <kern/kheap.h>
#include <kern/memory_manager.h>
uint32 start_address=KERNEL_HEAP_START;
struct allocte
{

	uint32 startaddress;
    int size;
};

struct allocte allocations[100];
int allocate_index=0;
void* kmalloc(unsigned int size)
{

	int roundsize=ROUNDUP(size,PAGE_SIZE);
	int count=roundsize/PAGE_SIZE;

    struct Frame_Info* ptr_to_frame_info;
	int temp;
	uint32 address=start_address;
	if(start_address>=(uint32)KERNEL_HEAP_MAX-roundsize)
	{
		return  NULL;
	}


    for(int i=0;i<count;i++)
	{


        temp=allocate_frame(& ptr_to_frame_info);

        if(temp==E_NO_MEM)
        		{
        			cprintf("No Space in memory");
        			break;
        		}

        map_frame(ptr_page_directory,ptr_to_frame_info,(void*)start_address,PERM_WRITEABLE);




        start_address=start_address+PAGE_SIZE;

	}

    allocations[allocate_index].size=count;
    allocations[allocate_index].startaddress=address;

    allocate_index++;

	return (void*)address;

}

void kfree(void* virtual_address)
{
	uint32 freestart;
	int count=0;

for (int i=0;i<allocate_index;i++)
{


	if(virtual_address==(void*)(allocations[i].startaddress))
	{
		freestart=allocations[i].startaddress;
		count=allocations[i].size;
		break;
	}

}


for(int i=0;i<count;i++)
{

	unmap_frame(ptr_page_directory,(void*)freestart);
	freestart=freestart+PAGE_SIZE;


}






}

unsigned int kheap_virtual_address(unsigned int physical_address)
{

  struct Frame_Info * ptr_frame_info=to_frame_info(physical_address);
  struct Frame_Info * temp2;
  uint32 * temp=NULL;

     uint32 address=KERNEL_HEAP_START;
     while(address<start_address)
     {
    	 temp2=get_frame_info(ptr_page_directory,(void*)address,&temp);


    	 if(temp2 == ptr_frame_info)
    	{

    		return address;

    	}

        address=address+PAGE_SIZE;
     }


     return 0;
}

unsigned int kheap_physical_address(unsigned int virtual_address)
{

	 uint32 * temp2=NULL;
     struct Frame_Info * ptr_Frame_info=NULL;
     ptr_Frame_info=get_frame_info(ptr_page_directory,(void*)virtual_address,&temp2);

     if(ptr_Frame_info!=NULL)
     {
     int PA=to_physical_address(ptr_Frame_info);
	 return PA;
     }

	//change this "return" according to your answer
	 return 0;
}
