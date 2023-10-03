import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ContentProjectionComponent } from './content-projection.component';

describe('ContentProjectionComponent', () => {
  let component: ContentProjectionComponent;
  let fixture: ComponentFixture<ContentProjectionComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [ContentProjectionComponent]
    });
    fixture = TestBed.createComponent(ContentProjectionComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
